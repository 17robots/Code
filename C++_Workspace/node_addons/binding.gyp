{
    "targets": [
    {
        "target_name": "cash_drawer",
        "sources": ["cash_drawer.cpp"],
        "include_dirs" : [ 
            "<!(node -e \"require('nan')\")"
        ]
    }
  ]
}