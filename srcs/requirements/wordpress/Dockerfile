FROM alpine:3.17

RUN apk update && apk add --no-cache \
		php82 \
		php82-fpm \
		php82-mysqli \
		php82-phar \
		php82-iconv \
		curl \
		mysql-client

WORKDIR /tmp
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin
RUN chmod +x /usr/local/bin/wp-cli.phar
RUN ln -s /usr/local/bin/wp-cli.phar /usr/local/bin/wp

RUN ln -sf /usr/sbin/php-fpm82 /usr/sbin/php-fpm
RUN ln -s /usr/bin/php82 /usr/bin/php

RUN sed -i 's|listen = 127.0.0.1:9000|listen = 9000|g' /etc/php82/php-fpm.d/www.conf

WORKDIR /var/www/html

COPY tools/entrypoint.sh /tmp/entrypoint.sh
RUN chmod 755 /tmp/entrypoint.sh

ENTRYPOINT ["/tmp/entrypoint.sh"]
