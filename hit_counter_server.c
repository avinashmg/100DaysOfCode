/**
 * File:    hit_counter_server.c
 *
 * Author:  Avinash M G (avinashmg@technologist.com)
 * Date:     24/07/2022
 * Session:   Day 2 of 100 Days of Code
 *
 * Summary of File:
 *
 *  This file contains code which serves files via http.
 *  I have used the tutorial from Mongoose library to
 *  make this.
 */
#include "mongoose.h"

int count = 0;
static void fn(struct mg_connection *c, int ev, void *ev_data, void *fn_data)
{
    if (ev == MG_EV_HTTP_MSG)
    {
        printf("%d\n", count);
        mg_http_reply(c, 200, "Content-Type: text/plain\r\n", "Count: %d\n", count++);
    }
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