#!bin/sh

if [ ! -d "/run/mysqld" ]; then
	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
fi

if [ ! -d "/var/lib/mysql/mysql" ]; then
	# init database
	mysql_install_db --user=mysql --datadir=/var/lib/mysql
	tfile='mktemp'
	cat << EOF > $tfile
USE mysql;
FLUSH PRIVILEGES;
DELETE FROM mysql.user WHERE User='';
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE} CHARACTER SET utf8 COLLATE utf8_general_ci;
GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}' WITH GRANT OPTION;
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* to '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_USER_PASSWORD}';
FLUSH PRIVILEGES;
EOF
	/usr/bin/mysqld --user=mysql --bootstrap < $tfile
	rm -f $tfile
fi

exec /usr/bin/mysqld --user=mysql $@

# mysql 데이터베이스 사용 명시
# 권한설정 하기위해 캐시삭제
# 빈 사용자이름 가진 사용자 모두삭제
# MYSQL_DATABASE 생성. 문자셋 utf8이고 Case Insensitive
# 로컬에서 실행되는 root 사용자에게 모든 데이터테이블에 모든 권한 부여. 권한부여도 가능
# MYSQL_DATABASE에 대해 MYSQL_USER에게 모든 권한 부여

# bootstrap은 서버 초기설정을 위해 사용됨.
