#!/bin/bash

echo "...Create wp-config.php"

wp config create \
    --path=/var/www/html \
    --locale=ja \
    --dbname=${DB_NAME} \
    --dbuser=${DB_USER} \
    --dbpass=${DB_PASSWORD} \
    --dbhost="mariadb"

echo "...Install WordPress"

wp core install \
    --path=/var/www/html \
    --url=$WP_URL \
    --title="$WP_TITLE" \
    --admin_user=$WP_ADMIN_USER \
    --admin_password=$WP_ADMIN_PASSWORD \
    --admin_email=$WP_ADMIN_EMAIL

echo "...Create Editor User"

wp user create \
    --path=/var/www/html \
    "$WP_EDITOR_USER" \
    "$WP_EDITOR_EMAIL" \
    --user_pass=${WP_EDITOR_PASSWORD} \
    --role=editor

php-fpm7.4 -F
