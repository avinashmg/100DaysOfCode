file_server:
	@echo "Building file server..."
	gcc file_server.c mongoose.c -o file_server

hit_counter:
	@echo "Building hit counter server..."
	gcc hit_counter_server.c mongoose.c -o hit_counter_server