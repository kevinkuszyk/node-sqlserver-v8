{
  'targets': [
    {
      'target_name': 'sqlserverv8',

      'sources': [
        'src/Column.cpp',
        'src/TimestampColumn.cpp',
        'src/Connection.cpp',
        'src/OdbcConnection.cpp',
        'src/OdbcStatement.cpp',
        'src/OdbcStatementCache.cpp',
        'src/OdbcPreparedStatement.cpp',
        'src/OdbcError.cpp',
        'src/OdbcConnectionBridge.cpp',
        'src/Operation.cpp',
        'src/OperationManager.cpp',
        'src/OdbcOperation.cpp',
        'src/BeginTranOperation.cpp',
        'src/CloseOperation.cpp',
        'src/CollectOperation.cpp',
        'src/EndTranOperation.cpp',
        'src/OpenOperation.cpp',
        'src/PrepareOperation.cpp',
        'src/ProcedureOperation.cpp',
        'src/QueryOperation.cpp',
        'src/ReadColumnOperation.cpp',
        'src/ReadNextResultOperation.cpp',
        'src/ReadRowOperation.cpp',
        'src/ResultSet.cpp',
        'src/Utility.cpp',
        'src/BoundDatum.cpp',
        'src/BoundDatumSet.cpp',
        'src/stdafx.cpp'
		],

      'include_dirs': [
        'src',
      ],

     'defines': [ 'NODE_GYP_V4'],

      'conditions': [
        [ 'OS=="win"', {
          'defines': [
            'UNICODE=1',
            '_UNICODE=1',
            '_SQLNCLI_ODBC_',
          ],
          }
        ]
      ]
    }
  ]
}