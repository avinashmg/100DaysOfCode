/**
 * File:    file_server.c
 *
 * Author:  Avinash M G (avinashmg@technologist.com)
 * Date:     23/07/2022
 * Session:   Day 2 of 100 Days of Code
 *
 * Summary of File:
 *
 *  This file contains code which serves files via http.
 *  I have used the tutorial from Mongoose library to
 *  make this.
 */
#include "mongoose.h"

static void fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
    struct mg_http_serve_opts opts = {.root_dir = "./server_public"}; // Serve local dir
    if (ev == MG_EV_HTTP_MSG)
        mg_http_serve_dir(c, ev_data, &opts);
}

int main(int argc, char *argv[])
{
    struct mg_mgr mgr;
    mg_mgr_init(&mgr);                                       // Init manager
    mg_http_listen(&mgr, "http://localhost:8000", fn, &mgr); // Setup listener
    for (;;)
        mg_mgr_poll(&mgr, 1000); // Event loop
    mg_mgr_free(&mgr);           // Cleanup
    return 0;
}