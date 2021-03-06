//---------------------------------------------------------------------------------------------------------------------------------
// File: ResultSet.h
// Contents: ResultSet object that holds metadata and current column to return to Javascript
// 
// Copyright Microsoft Corporation and contributors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
//
// You may obtain a copy of the License at:
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//---------------------------------------------------------------------------------------------------------------------------------

#pragma once

#include "Column.h"

namespace mssql
{
    using namespace std;

    class ResultSet
    {

    public:

        struct ColumnDefinition
        {
            wstring name;
            SQLULEN columnSize;
            SQLSMALLINT dataType;
            wstring dataTypeName;
            SQLSMALLINT decimalDigits;
            SQLSMALLINT nullable;
            wstring udtTypeName;
        };

        ResultSet(int columns) 
            : rowcount(0),
              endOfRows(true)
        {
            metadata.resize(columns);
            column.reset();
        }
  
        ColumnDefinition & get_meta_data(int column)
        {
            return metadata[column];
        }

        size_t get_column_count() const
        {
            return metadata.size();
        }

        Handle<Value> meta_to_value();

        void SetColumn(shared_ptr<Column> column)
        {
            this->column = column;
        }

        shared_ptr<Column> get_column() const
        {
            return column;
        }

        SQLLEN row_count() const
        {
            return rowcount;
        }

        bool EndOfRows() const
        {
            return endOfRows;
        }

    private:
		static Local<Object> get_entry(const nodeTypeFactory & fact, const ColumnDefinition & definition);
        vector<ColumnDefinition> metadata;
        SQLLEN rowcount;
        bool endOfRows;
        shared_ptr<Column> column;


		friend class OdbcStatement;
    };
}
