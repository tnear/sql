// SQLite.cpp
// Basic usage of SQLite in C++
// To build: Ctrl+Shift+B (or Terminal -> Run Build Task)
//           Needed because this builds sqlite in a separate C file then links both.

#include <cassert>
#include <filesystem>
#include <functional>
#include <iostream>
#include <string>
#include "SQLite/sqlite3.h"

using namespace std;

const string DATABASE_NAME = "KeyValue.db";

class RAIIDeleter
{
public:
    RAIIDeleter(std::function<void(void)> onCleanup)
        : _onCleanup(onCleanup) // set function to be called as member variable
    {
    }

    ~RAIIDeleter()
    {
        _onCleanup(); // use a destructor to ensure onCleanup is always called
    }

private:
    std::function<void(void)> _onCleanup;
};

void closeDatabase(sqlite3 *db)
{
    if (!db)
        return;

    sqlite3_close(db);

    std::filesystem::path path { DATABASE_NAME };
    std::filesystem::remove(path);
}

void createKeyValueTable(sqlite3 &db)
{
    // create the schema for the database table
    const string expression = \
        "create table if not exists KeyValue(" \
        "key   text primary key unique," \
        "value blob);";

    int rc = sqlite3_exec(&db, expression.c_str(), 0, 0, nullptr);
    assert(rc == SQLITE_OK);

    // index the table for efficient lookup
    const string index = "create index key_index on KeyValue (key);";
    rc = sqlite3_exec(&db, index.c_str(), 0, 0, 0);
    assert(rc == SQLITE_OK);
}

void insertKeyValueData(sqlite3 &db, const string &key, const int val)
{
    // create prepared statement with placeholders
    const string expression = "insert into KeyValue (key, value) values (?, ?);";

    sqlite3_stmt *stmt = nullptr;
    int rc = sqlite3_prepare_v2(&db, expression.c_str(), -1, &stmt, 0);
    assert(rc == SQLITE_OK);

    // bind values to the prepared statement
    int idx = 1; // placeholders are 1-indexed
    sqlite3_bind_text(stmt, idx++, key.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, idx++, val);

    // execute the prepared statement
    rc = sqlite3_step(stmt);
    assert(rc == SQLITE_DONE);

    // finalize the statement
    sqlite3_finalize(stmt);
}

int lookupValue(sqlite3 &db, const string &key)
{
    int result = -1;
    const string query = "select value from KeyValue where key = ?;";
    sqlite3_stmt *stmt = nullptr;

    int rc = sqlite3_prepare_v2(&db, query.c_str(), -1, &stmt, nullptr);
    assert(rc == SQLITE_OK);

    int idx = 1; // placeholders are 1-indexed
    sqlite3_bind_text(stmt, idx++, key.c_str(), -1, SQLITE_STATIC);

    int count = 0;
    rc = sqlite3_step(stmt);
    // note: this uses an 'if' statement instead of a while loop because keys are unique
    if (rc == SQLITE_ROW)
    {
        // found data
        result = sqlite3_column_int(stmt, 0);
    }

    sqlite3_finalize(stmt);

    return result;
}

void testKeyValue()
{
    sqlite3 *db = nullptr;
    int exit = sqlite3_open(DATABASE_NAME.c_str(), &db);
    assert(exit == SQLITE_OK);

    RAIIDeleter d([&]() { closeDatabase(db); });

    createKeyValueTable(*db);

    // insert a few values
    insertKeyValueData(*db, "key", 123);
    int result = lookupValue(*db, "key");
    assert(result == 123);

    insertKeyValueData(*db, "2ndKey", 456);
    result = lookupValue(*db, "2ndKey");
    assert(result == 456);

    insertKeyValueData(*db, "Key3", -101);
    result = lookupValue(*db, "Key3");
    assert(result == -101);

    // non-existent key
    result = lookupValue(*db, "FakeKey");
    assert(result == -1);
}

void test()
{
    testKeyValue();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
