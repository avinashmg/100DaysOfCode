file_server:
	@echo "Building file server..."
	gcc file_server.c mongoose.c -o file_server

hit_counter:
	@echo "Building hit counter server..."
	gcc hit_counter_server.c mongoose.c -o hit_counter_server

sqlite:
	@echo "Building sqlite test binary..."
	@gcc sqlite_testing.c sqlite3.c -o sqlite_test -ldl -pthread
	@./sqlite_test