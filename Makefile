file_server:
	@echo "Building file server..."
	gcc file_server.c mongoose.c -o file_server