#include <node.h>
#include <string>
#include <iostream>
#include "../blake2_code_20121229/sse/blake2.h"
#include "b2sum.h"
typedef int ( *blake2fn )( FILE *, void * );

using namespace v8;

//Handle<Value> getHash(const Arguments& args) {
//    HandleScope scope;
//
//    // get filename from arguments
//    if (args.Length() < 1) {
//        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
//        return scope.Close(Undefined());
//    }
//    Local<String> filename ;
//    filename = args[0]->ToString() ;
//    v8::String::Utf8Value str(args[0]) ;
//
//    blake2fn blake2_stream = blake2b_stream;
//    size_t outlen   = BLAKE2B_OUTBYTES;
//    unsigned char hash[BLAKE2B_OUTBYTES] = {0};
//    opterr = 1;
//
//    blake2_stream = blake2b_stream;
//    outlen = BLAKE2B_OUTBYTES;
//
//    // blake2b
//    blake2_stream = blake2b_stream;
//    outlen = BLAKE2B_OUTBYTES;
//
//    FILE *f = NULL;
//    f = fopen(*str, "rb" );
//
//    if( !f ) {
//        ThrowException(Exception::TypeError(String::New("Could not open file.")));
//        return scope.Close(Undefined());
//    }
//
//    if( blake2_stream( f, hash ) < 0 ) {
//        ThrowException(Exception::TypeError(String::New("Failed to hash.")));
//        return scope.Close(Undefined());
//    }
//
//    char retstr[256] = "" ;
//    char tmp[2] ;
//    for( int j = 0; j < outlen; ++j ){
//        sprintf(tmp,"%02x",hash[j]) ;
//        strcat(retstr,tmp) ;
//    }
//
//    Local<String> h = String::New(retstr);
//    return scope.Close(h);
//}

Handle<Value> getHash2(const Arguments& args) {
    HandleScope scope;

    // get filename from arguments
    if (args.Length() < 2) {
        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
        return scope.Close(Undefined());
    }
    v8::String::Utf8Value filename(args[0]) ;

    // get function type
    v8::String::Utf8Value functype(args[1]) ;


    blake2fn blake2_stream = blake2b_stream;
    size_t outlen   = BLAKE2B_OUTBYTES;
    unsigned char hash[BLAKE2B_OUTBYTES] = {0};
    opterr = 1;

    blake2_stream = blake2b_stream;
    outlen = BLAKE2B_OUTBYTES;

    // Select function
    if ( strcmp(*functype, "blake2b") == 0 ) {
        blake2_stream = blake2b_stream;
        outlen = BLAKE2B_OUTBYTES;
    } else if (strcmp(*functype, "blake2bp") == 0 ) {
        blake2_stream = blake2bp_stream;
        outlen = BLAKE2B_OUTBYTES;
    } else if (strcmp(*functype, "blake2s") == 0 ) {
        blake2_stream = blake2s_stream;
        outlen = BLAKE2S_OUTBYTES;
    } else if (strcmp(*functype, "blake2sp") == 0 ) {
        blake2_stream = blake2sp_stream;
        outlen = BLAKE2S_OUTBYTES;
    } else {
        ThrowException(Exception::TypeError(String::New("Invalid type.")));
        return scope.Close(Undefined());
    }

    FILE *f = NULL;
    f = fopen(*filename, "rb" );

    if( !f ) {
        ThrowException(Exception::TypeError(String::New("Could not open file.")));
        return scope.Close(Undefined());
    }

    if( blake2_stream( f, hash ) < 0 ) {
        ThrowException(Exception::TypeError(String::New("Failed to hash.")));
        return scope.Close(Undefined());
    }

    char retstr[256] = "" ;
    char tmp[2] ;
    for( int j = 0; j < outlen; ++j ){
        sprintf(tmp,"%02x",hash[j]) ;
        strcat(retstr,tmp) ;
    }

    Local<String> h = String::New(retstr);
    return scope.Close(h);
}

//Handle<String> getHash(const Arguments& args) {
//    HandleScope scope;
//
//    // get filename from arguments
//    if (args.Length() < 2) {
//        ThrowException(Exception::TypeError(String::New("Wrong number of arguments")));
//        return scope.Close(Undefined());
//    }
//    v8::String::Utf8Value filename(args[0]) ;
//
//    // get function type
//    v8::String::Utf8Value functype(args[1]) ;
//
//    blake2fn blake2_stream = blake2b_stream;
//    size_t outlen   = BLAKE2B_OUTBYTES;
//    unsigned char hash[BLAKE2B_OUTBYTES] = {0};
//    opterr = 1;
//
//    blake2_stream = blake2b_stream;
//    outlen = BLAKE2B_OUTBYTES;
//
//    // Select function
//    if ( strcmp(*functype, "blake2b") == 0 ) {
//        blake2_stream = blake2b_stream;
//        outlen = BLAKE2B_OUTBYTES;
//    } else if (strcmp(*functype, "blake2bp") == 0 ) {
//        blake2_stream = blake2bp_stream;
//        outlen = BLAKE2B_OUTBYTES;
//    } else if (strcmp(*functype, "blake2s") == 0 ) {
//        blake2_stream = blake2s_stream;
//        outlen = BLAKE2S_OUTBYTES;
//    } else if (strcmp(*functype, "blake2sp") == 0 ) {
//        blake2_stream = blake2sp_stream;
//        outlen = BLAKE2S_OUTBYTES;
//    } else {
//        ThrowException(Exception::TypeError(String::New("Invalid type.")));
//        return scope.Close(Undefined());
//    }
//
//    FILE *f = NULL;
//    f = fopen(*filename, "rb" );
//
//    if( !f ) {
//        ThrowException(Exception::TypeError(String::New("Could not open file.")));
//        return scope.Close(Undefined());
//    }
//
//    if( blake2_stream( f, hash ) < 0 ) {
//        ThrowException(Exception::TypeError(String::New("Failed to hash.")));
//        return scope.Close(Undefined());
//    }
//
//    char retstr[256] = "" ;
//    char tmp[2] ;
//    for( int j = 0; j < outlen; ++j ){
//        sprintf(tmp,"%02x",hash[j]) ;
//        strcat(retstr,tmp) ;
//    }
//
//    Local<String> ret = String::New(retstr);
//    return scope.Close(ret);
//}

void Init(Handle<Object> target) {
  //target->Set(String::NewSymbol("sum"), FunctionTemplate::New(getHash)->GetFunction());
  target->Set(String::NewSymbol("blake2"), FunctionTemplate::New(getHash2)->GetFunction());
}

NODE_MODULE(blake2, Init)
