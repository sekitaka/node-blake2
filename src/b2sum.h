#ifdef __cplusplus
extern "C" {
    int blake2b_stream( FILE *stream, void *resstream ) ;
    int blake2bp_stream( FILE *stream, void *resstream ) ;
    int blake2s_stream( FILE *stream, void *resstream );
    int blake2sp_stream( FILE *stream, void *resstream );
#endif

#ifdef __cplusplus
}
#endif
