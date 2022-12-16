# Based on original work by David Manura
# Copyright (C) 2007-2012 LuaDist.
# Copyright (C) 2013 Brian Sidebotham

# Redistribution and use of this file is allowed according to the terms of the
# MIT license.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

set(OPENSSL_SSL_SRC_DIR "${OPENSSL_SRC_DIR}/ssl")
set(OPENSSL_SSL_BIN_DIR "${OPENSSL_BIN_DIR}/ssl")

if(BUILD_SHARED_LIBS)
    add_definitions(-DOPENSSL_BUILD_SHLIBSSL)
endif()

set(LIBSRC
    "${OPENSSL_SSL_SRC_DIR}/bio_ssl.c"
    "${OPENSSL_SSL_SRC_DIR}/d1_lib.c"
    "${OPENSSL_SSL_SRC_DIR}/d1_msg.c"
    "${OPENSSL_SSL_SRC_DIR}/d1_srtp.c"
    "${OPENSSL_SSL_SRC_DIR}/methods.c"
    "${OPENSSL_SSL_SRC_DIR}/packet.c"
    "${OPENSSL_SSL_SRC_DIR}/pqueue.c"
    "${OPENSSL_SSL_SRC_DIR}/s3_cbc.c"
    "${OPENSSL_SSL_SRC_DIR}/s3_enc.c"
    "${OPENSSL_SSL_SRC_DIR}/s3_lib.c"
    "${OPENSSL_SSL_SRC_DIR}/s3_msg.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_asn1.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_cert.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_ciph.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_conf.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_err.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_init.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_lib.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_mcnf.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_rsa.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_sess.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_stat.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_txt.c"
    "${OPENSSL_SSL_SRC_DIR}/ssl_utst.c"
    "${OPENSSL_SSL_SRC_DIR}/t1_enc.c"
    "${OPENSSL_SSL_SRC_DIR}/t1_lib.c"
    "${OPENSSL_SSL_SRC_DIR}/t1_trce.c"
    "${OPENSSL_SSL_SRC_DIR}/tls13_enc.c"
    "${OPENSSL_SSL_SRC_DIR}/tls_srp.c"
    "${OPENSSL_SSL_SRC_DIR}/record/dtls1_bitmap.c"
    "${OPENSSL_SSL_SRC_DIR}/record/rec_layer_d1.c"
    "${OPENSSL_SSL_SRC_DIR}/record/rec_layer_s3.c"
    "${OPENSSL_SSL_SRC_DIR}/record/ssl3_buffer.c"
    "${OPENSSL_SSL_SRC_DIR}/record/ssl3_record.c"
    "${OPENSSL_SSL_SRC_DIR}/record/ssl3_record_tls13.c"
    "${OPENSSL_SSL_SRC_DIR}/statem/extensions.c"
    "${OPENSSL_SSL_SRC_DIR}/statem/extensions_clnt.c"
    "${OPENSSL_SSL_SRC_DIR}/statem/extensions_cust.c"
    "${OPENSSL_SSL_SRC_DIR}/statem/extensions_srvr.c"
    "${OPENSSL_SSL_SRC_DIR}/statem/statem.c"
    "${OPENSSL_SSL_SRC_DIR}/statem/statem_clnt.c"
    "${OPENSSL_SSL_SRC_DIR}/statem/statem_dtls.c"
    "${OPENSSL_SSL_SRC_DIR}/statem/statem_lib.c"
    "${OPENSSL_SSL_SRC_DIR}/statem/statem_srvr.c")

add_library(ssl ${LIBSRC})

source_group(TREE ${OPENSSL_SSL_SRC_DIR} PREFIX "" FILES ${LIBSRC})

if(APPLE)
    target_compile_options(ssl
      PRIVATE
        -Wno-shorten-64-to-32
        -Wno-comma
        -Wno-unreachable-code
    )
endif()

target_link_libraries(ssl crypto)

set_target_properties(ssl PROPERTIES
    VERSION "${LIB_VERSION}" SOVERSION "${LIB_SOVERSION}")

install(TARGETS ssl
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)
