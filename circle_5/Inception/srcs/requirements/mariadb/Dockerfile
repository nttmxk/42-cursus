FROM alpine:3.17

RUN apk update && apk add --no-cache \
		mariadb \
		mariadb-client

RUN sed -i "s|skip-networking|skip-networking=0|g" /etc/my.cnf.d/mariadb-server.cnf
RUN sed -i "s|#bind-address=0.0.0.0|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf

COPY tools/entrypoint.sh /tmp/entrypoint.sh
RUN chmod 755 /tmp/entrypoint.sh

ENTRYPOINT ["/tmp/entrypoint.sh"]

# skip-networking은 로컬소켓통신만 허용함. 컨테이너 간의 통신은 네트워크 소켓 사용 
# bind-address는 서버가 리스닝할 IP주소를 설정. 모든IP에서 요청수신
