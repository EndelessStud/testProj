#!/bin/bash

service postgresql start
psql -U postgres -c "CREATE USER myuser WITH PASSWORD '33333333';"
psql -U postgres -c "CREATE DATABASE mydb;"
psql -U postgres -c "select pg_reload_conf();"
psql -U postgres -c "GRANT ALL PRIVILEGES ON DATABASE mydb TO myuser;"
psql -U postgres -d mydb -c "CREATE TABLE country (name VARCHAR(50));"
psql -U postgres -d mydb -c  "CREATE TABLE country (id SERIAL PRIMARY KEY, name VARCHAR(50));"
psql -U postgres -d mydb -c "GRANT ALL PRIVILEGES ON TABLE country TO myuser;"
service postgresql restart

mosquitto -p 8884 &

/usr/bin/TestProject sub
