// -Ileveldb-read-only/include -Lleveldb-read-only -lleveldb -lpthread

#include "leveldb/db.h"
#include <iostream>

using namespace std;

int main(){
  leveldb::DB *db;
  leveldb::Options options;

  options.create_if_missing = true;

  // 闁嬪暉鏁告摎搴