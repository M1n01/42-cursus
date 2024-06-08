FROM debian:bullseye-slim

RUN apt-get update && apt-get install -y nginx openssl --no-install-recommends &&\
    apt-get clean && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/html && chown -R www-data:www-data /var/www/html &&\
    mkdir -p /run/nginx && chown -R www-data:www-data /run/nginx &&\
    mkdir -p /etc/nginx/ssl && chown -R www-data:www-data /etc/nginx/ssl

COPY ./conf/nginx.conf /etc/nginx/
COPY ./conf/default.conf /etc/nginx/conf.d/

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/nginx/ssl/minabe.42.fr.key -out /etc/nginx/ssl/minabe.42.fr.crt -subj "/C=JP/ST=Tokyo/O=42Tokyo/OU=42/CN=minabe.42.fr"

EXPOSE 443
CMD ["nginx", "-g", "daemon off;"]
