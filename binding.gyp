{
    "targets": [
        {
            "target_name": "bind",
            # NOTE: is not necessary to validate status when this flag is active?
            #  "cflags!": ["-fno-exceptions"],
            "sources": [
                "./src/index.c"
            ],
        }
    ]
}
