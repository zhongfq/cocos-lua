
# Fetch OpenSSL sources at the desired release tag:

```
git clone https://github.com/openssl/openssl.git
cd openssl
git checkout OpenSSL_1_1_1d
```

# Import openssl-cmake build system in OpenSSL sources:

```
git clone https://github.com/devolutions/openssl-cmake.git
git -C openssl-cmake checkout-index -a -f --prefix=../
```
