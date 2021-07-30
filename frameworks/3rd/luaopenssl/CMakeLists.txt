cmake_minimum_required(VERSION 3.6)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
add_definitions(-DPTHREADS)

if(WIN32)
    set(EXTRA_LIBS "ws2_32.lib" "crypt32.lib")
endif()

set(OPENSSL_SOURCE
    deps/auxiliar/auxiliar.c
    deps/auxiliar/auxiliar.h
    deps/auxiliar/subsidiar.c
    deps/auxiliar/subsidiar.h
    deps/lua-compat/c-api/compat-5.3.h
    deps/lua-compat/lprefix.h
    asn1.c
    bio.c
    callback.c
    cipher.c
    cms.c
    compat.c
    crl.c
    csr.c
    dh.c
    digest.c
    dsa.c
    ec.c
    engine.c
    hmac.c
    lbn.c
    lhash.c
    misc.c
    ocsp.c
    oids.txt
    openssl.c
    openssl.h
    ots.c
    pkcs12.c
    pkcs7.c
    pkey.c
    private.h
    private.h
    rsa.c
    sk.h
    sk.h
    srp.c
    ssl_options.h
    ssl.c
    stdatomic.h
    th-lock.c
    util.c
    x509.c
    xalgor.c
    xattrs.c
    xexts.c
    xname.c
    xstore.c
)

add_library(luaopenssl ${OPENSSL_SOURCE})

if(APPLE)
    target_compile_options(luaopenssl PRIVATE -Wno-shorten-64-to-32)
    target_compile_options(luaopenssl PRIVATE -Wno-strict-prototypes)
    target_compile_options(luaopenssl PRIVATE -Wno-incompatible-function-pointer-types)
    target_compile_options(luaopenssl PRIVATE -Wno-incompatible-pointer-types)
endif()

target_link_libraries(luaopenssl 
	PRIVATE xgame
	PRIVATE cocos2d
    PUBLIC ${EXTRA_LIBS}
    PUBLIC Threads::Threads
)

target_include_directories(luaopenssl
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..
    deps
    deps/lua-compat/c-api
    deps/auxiliar
)

set_target_properties(luaopenssl PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "Internal"
)

if(XCODE OR VS)
    cocos_mark_code_files("luaopenssl" GROUPBASE "${CMAKE_CURRENT_SOURCE_DIR}")
endif()