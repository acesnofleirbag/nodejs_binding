#ifndef LIB_MAIN_H
#define LIB_MAIN_H

#include <node/node_api.h>
#include <node/js_native_api_types.h>

napi_value 
sum(napi_env env, napi_callback_info info) {
    int args[2] = { 0, 0 };
    size_t argc = 2;
    napi_value argv[2], result;
    napi_status status;

    // NOTE: gets info from js context
    status = napi_get_cb_info(env, info, &argc, argv, NULL, NULL);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "failed to parse args");
    }

    // NOTE: assign 1st arg to args array 'index 0'
    status = napi_get_value_int32(env, argv[0], &args[0]);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "the 1st arg is an invalid number");
    }

    // NOTE: assign 2nd arg to args array 'index 1'
    status = napi_get_value_int32(env, argv[1], &args[1]);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "the 2nd arg is an invalid number");
    }

    int sum = args[0] + args[1];

    status = napi_create_int32(env, sum, &result);

    if (status != napi_ok) {
        napi_throw_error(env, NULL, "unable to create return value");
    }

    return result;
}

#endif
