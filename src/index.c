#include <node/node_api.h>
#include <node/js_native_api_types.h>

#include "lib/main.h"

// NOTE: 
// * 1st arg: is a v8 VM isolation process, have a separated heap and garbage collector
// * 2nd arg: bind object to be exported
napi_value 
init(napi_env env, napi_value exports) {
    napi_status status;
    napi_value fn;

    // NOTE: assign 'sum' to 'fn' 
    status = napi_create_function(env, /* name= */ NULL, /* length= */ 0, sum, NULL, &fn);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "unable to wrap native function");
    }

    // NOTE: export fn as 'bindSum'
    status = napi_set_named_property(env, exports, "bindSum", fn);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "unable to populate exports");
    }

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
