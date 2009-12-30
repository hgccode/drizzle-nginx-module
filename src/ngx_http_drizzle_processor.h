#ifndef NGX_HTTP_DRIZZLE_PROCESSOR_H
#define NGX_HTTP_DRIZZLE_PROCESSOR_H

#include <ngx_http.h>
#include <ngx_core.h>

#include "ngx_http_drizzle_module.h"
#include "ngx_http_upstream_drizzle.h"

ngx_int_t ngx_http_drizzle_process_events(ngx_http_request_t *r);

ngx_int_t ngx_http_upstream_drizzle_done(ngx_http_request_t *r,
        ngx_http_upstream_t *u, ngx_http_upstream_drizzle_peer_data_t *dp);

/* faked upstream_keepalive_peer_data_t */
typedef struct {
    void                              *conf;

    ngx_http_upstream_t               *upstream;

    void                              *data;

    ngx_event_get_peer_pt              original_get_peer;
    ngx_event_free_peer_pt             original_free_peer;

    ngx_uint_t                         failed;       /* unsigned:1 */

} ngx_http_upstream_faked_keepalive_peer_data_t;

#endif /* NGX_HTTP_DRIZZLE_PROCESSOR_H */

