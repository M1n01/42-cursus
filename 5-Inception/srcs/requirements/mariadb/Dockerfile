FROM debian:bullseye-slim

RUN apt-get update && apt-get install -y --no-install-recommends \
    mariadb-server \
    && rm -rf /var/lib/apt/lists/*

RUN set -x && \
    mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld

VOLUME /var/lib/mysql

COPY ./tools/docker-entrypoint.sh /usr/local/bin/
COPY ./conf/my.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
RUN chmod +x /usr/local/bin/docker-entrypoint.sh

EXPOSE 3306
ENTRYPOINT ["docker-entrypoint.sh"]
