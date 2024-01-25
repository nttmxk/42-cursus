FROM alpine:3.17

RUN	apk update && apk add --no-cache \
		nginx \
		openssl

COPY conf/default.conf /etc/nginx/http.d
RUN echo "daemon off;" >> /etc/nginx/nginx.conf

RUN openssl req \
		-x509 \
		-days 365 \
		-nodes \
		-newkey rsa:2048 \
		-keyout /etc/ssl/private/jinoh.42.fr.key \
		-out /etc/ssl/certs/jinoh.42.fr.crt \
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42seoul/OU=student/CN=www.jinoh.42.fr"

EXPOSE 443

ENTRYPOINT [ "nginx" ]
