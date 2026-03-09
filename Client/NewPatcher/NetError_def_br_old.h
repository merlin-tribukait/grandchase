#ifndef __NEVER_DEFINED_MACRO__
#define __NEVER_DEFINED_MACRO__
#define NET_ERROR(VAL, VAL2) VAL,
enum
{
#endif

    NET_ERROR( NET_OK = 0,              Sucesso	                                 )
    NET_ERROR( ERR_UNKNOWN,             Erro desconhecido	                     )
    NET_ERROR( PS_INIT_PATCHER,         Inicializando	                         )
    NET_ERROR( PS_CHECK_PATCHER,        Confirmando atualizacao do Patcher	     )
    NET_ERROR( PS_CHECK_VERSION,         Verificando versao	                     )
    NET_ERROR( PS_CONNECT_PATCHSVR,     Conectando ao servidor de patch	     )
    NET_ERROR( PS_CONNECT_PATCHSVR_OK,  Conexao estabelecida	                     )
    NET_ERROR( PS_GET_PATCHLIST,         Obtendo lista de atualizacoes	         )
    NET_ERROR( PS_GET_PATCHLIST_OK,      Lista obtida	                         )
    NET_ERROR( PS_DOWNLOAD_PATCH,        Baixando atualizacoes	                     )
    NET_ERROR( PS_DOWNLOAD_PATCH_OK,     Download concluido	                     )
    NET_ERROR( PS_APPLY_PATCH,           Aplicando atualizacoes	                     )
    NET_ERROR( PS_APPLY_PATCH_OK,        Aplicacao concluida	                     )
    NET_ERROR( PS_COMPLETE_PATCH,        Patch completo	                         )
    NET_ERROR( PS_COMPLETE_PATCH_OK,     Patch concluido com sucesso	         )
    NET_ERROR( PS_CANCEL_PATCH,          Cancelando patch	                         )
    NET_ERROR( PS_CANCEL_PATCH_OK,       Patch cancelado	                         )
    NET_ERROR( PS_ERROR_PATCH,           Erro durante patch	                     )
    NET_ERROR( PS_ERROR_PATCH_OK,        Erro de patch detectado	                 )

#ifdef __NEVER_DEFINED_MACRO__
};
#endif

#endif // __NEVER_DEFINED_MACRO__
    NET_ERROR( PS_PATCHER_PATCH,        Atualizando Patcher	                     )
    NET_ERROR( PS_PROGRAMPATH_ERR,      N찾o foi poss챠vel encontrar arquivo	     )
    NET_ERROR( PS_WEBOPEN_ERR,          Erro na conex찾o de rede	                 )
    NET_ERROR( PS_PATCHSRC_ERR,         Falha na conex찾o com servidor de patch	 )
    NET_ERROR( PS_DOWN_PATCHPATH_ERR,   Falha no download de arquivo de patch	 )
    NET_ERROR( PS_PATCHPATH_READ_ERR,   Falha na leitura do arquivo de patch	 )
    NET_ERROR( PS_NEWVER_DOWN_ERR,      Falha no donwload de vers찾o	             )
    NET_ERROR( PS_VER_READ_ERR,         Erro na vers찾o de programa	             )
    NET_ERROR( PS_PATCHSTR,             Falha na leitura de texto	             )
    NET_ERROR( PS_IMAGE_NO_EXIST,       IMAGE.KOM n찾o existe	                 )
    NET_ERROR( PS_IMAGE_NO_LOAD,        Falha no carregamento de         	     )
    NET_ERROR( PS_PATCHTIME_MSG,        Servidor fechado para manuten챌찾o            )
    NET_ERROR( PS_EXECUTE_IN_SYSTEM_FOLDER,        "Seu jogo est찼 instalado em um diret처rio inv찼lido. Por favor, reinstale o jogo usando o cliente mais recente dispon챠vel" )
NET_ERROR( ERR_SENTINEL,    ERR_SENTINEL )

#ifdef __NEVER_DEFINED_MACRO__
};
#undef NET_ERROR
#endif
