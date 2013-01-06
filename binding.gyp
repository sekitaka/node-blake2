{
    "targets": [
        {
            "target_name": "blake2",
            "sources": [ "src/blake2.cpp",
                         "blake2_code_20121229/b2sum/b2sum.c",
                         "blake2_code_20121229/sse/blake2b.c",
                         "blake2_code_20121229/sse/blake2bp.c",
                         "blake2_code_20121229/sse/blake2s.c",
                         "blake2_code_20121229/sse/blake2sp.c"
            ],
            "include_dirs":["blake2_code_20121229/sse/"],
            "cflags": ["-std=c99"] # ignore warning
        }
    ]
}