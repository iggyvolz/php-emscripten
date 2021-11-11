FROM emscripten/emsdk AS build
ARG VERSION=8.1.0RC6
WORKDIR /usr/src
RUN wget https://downloads.php.net/~ramsey/php-${VERSION}.tar.xz
RUN tar xf php-$VERSION.tar.xz
RUN mv php-$VERSION php
WORKDIR /usr/src/php
RUN emconfigure ./configure --disable-all --disable-fiber-asm --without-pcre-jit --disable-cgi --disable-cli --disable-phpdbg --enable-embed
RUN emmake make -j`nproc`
RUN emmake make -j`nproc` install
COPY embed.c . 
RUN emcc embed.c -o php.js \
     $(php-config --includes) \
	-L$(php-config --prefix)/lib \
	-lphp -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
	-s EXPORTED_FUNCTIONS='["_run_php"]' -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' -s ALLOW_MEMORY_GROWTH=1
FROM scratch 
COPY --from=build /usr/src/php/php.js /
COPY --from=build /usr/src/php/php.wasm /
