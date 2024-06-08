# Variables
COMPOSE_FILE := srcs/docker-compose.yml
ENV_FILE := srcs/.env

# Volume directories
VOLUME_PATH := /home/minabe/data

WP_LOGS_DIR := $(VOLUME_PATH)/wordpress/logs
DB_LOGS_DIR := $(VOLUME_PATH)/mariadb/logs
NGINX_LOGS_DIR := $(VOLUME_PATH)/nginx/logs

# Targets
all: up

up:
	sudo mkdir -p $(WP_LOGS_DIR) $(DB_LOGS_DIR) ${NGINX_LOGS_DIR}
	docker compose -f $(COMPOSE_FILE) --env-file $(ENV_FILE) up -d --build

clean:
	docker compose -f $(COMPOSE_FILE) --env-file $(ENV_FILE) down -v --rmi all --remove-orphans

fclean: clean
	docker system prune -f

re: fclean all

.PHONY: all up clean fclean re
