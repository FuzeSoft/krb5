/*
 * $Source$
 * $Author$
 * $Id$
 *
 * Copyright 1990 by the Massachusetts Institute of Technology.
 *
 * For copying and distribution information, please see the file
 * <krb5/copyright.h>.
 *
 * #defines for using generic encoder routine.
 */

#include <krb5/copyright.h>

#ifndef KRB5_ENCODE_DEFS__
#define KRB5_ENCODE_DEFS__

typedef	int (*encoder_func) PROTOTYPE((PE *, int, int, char *, krb5_pointer));
typedef void (*free_func) PROTOTYPE((krb5_pointer ));
typedef krb5_pointer (*translator_func) PROTOTYPE((krb5_const_pointer, int * ));
typedef int (*decoder_func) PROTOTYPE((PE, int, int, char *, krb5_pointer));

/* encode.c */
krb5_error_code krb5_encode_generic
    PROTOTYPE((krb5_const_pointer,
	       krb5_data **,
	       encoder_func,
	       translator_func,
	       free_func));
krb5_error_code krb5_decode_generic
	PROTOTYPE((const krb5_data *,
		   krb5_pointer *,
		   decoder_func,
		   translator_func,
		   free_func));

/* decode_arp.c */
krb5_error_code decode_krb5_as_rep
	PROTOTYPE((krb5_data *,
		   krb5_kdc_rep **));

/* decode_arq.c */
krb5_error_code decode_krb5_as_req
	PROTOTYPE((krb5_data *,
		   krb5_kdc_req **));

/* encode_arp.c */
krb5_error_code encode_krb5_as_rep
	PROTOTYPE((const krb5_kdc_rep *,
		   krb5_data **));

/* encode_arq.c */
krb5_error_code encode_krb5_as_req
	PROTOTYPE((const krb5_kdc_req *,
		   krb5_data **));

#define encode_krb5_authenticator(pauth, output) \
    krb5_encode_generic((krb5_const_pointer)pauth,  output, \
		   (encoder_func) encode_KRB5_Authenticator, \
		   (translator_func) krb5_authenticator2KRB5_Authenticator, \
		   (free_func) free_KRB5_Authenticator)
#define decode_krb5_authenticator(pauth, output) \
    krb5_decode_generic(pauth, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_Authenticator, \
		   (translator_func) KRB5_Authenticator2krb5_authenticator, \
		   (free_func) free_KRB5_Authenticator)
						
#define encode_krb5_ticket(ptick, output) \
    krb5_encode_generic((krb5_const_pointer)ptick,  output, \
		   (encoder_func) encode_KRB5_Ticket, \
		   (translator_func) krb5_ticket2KRB5_Ticket, \
		   (free_func) free_KRB5_Ticket)
#define decode_krb5_ticket(ptick, output) \
    krb5_decode_generic(ptick, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_Ticket, \
		   (translator_func) KRB5_Ticket2krb5_ticket, \
		   (free_func) free_KRB5_Ticket)

#define encode_krb5_enc_tkt_part(ptick, output) \
    krb5_encode_generic((krb5_const_pointer)ptick,  output, \
		   (encoder_func) encode_KRB5_EncTicketPart, \
		   (translator_func) krb5_enc_tkt_part2KRB5_EncTicketPart, \
		   (free_func) free_KRB5_EncTicketPart)
#define decode_krb5_enc_tkt_part(ptick, output) \
    krb5_decode_generic(ptick, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_EncTicketPart, \
		   (translator_func) KRB5_EncTicketPart2krb5_enc_tkt_part, \
		   (free_func) free_KRB5_EncTicketPart)

#define encode_krb5_enc_kdc_rep_part(req, output) \
    krb5_encode_generic((krb5_const_pointer)req, output, \
		   (encoder_func) encode_KRB5_EncTGSRepPart, \
		   (translator_func) krb5_enc_kdc_rep_part2KRB5_EncTGSRepPart, \
		   (free_func) free_KRB5_EncTGSRepPart)
#define decode_krb5_enc_kdc_rep_part(req, output) \
    krb5_decode_generic(req, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_EncTGSRepPart, \
		   (translator_func) KRB5_EncTGSRepPart2krb5_enc_kdc_rep_part, \
		   (free_func) free_KRB5_EncTGSRepPart)

#define encode_krb5_tgs_rep(req, output) \
    krb5_encode_generic((krb5_const_pointer)req, output, \
		   (encoder_func) encode_KRB5_TGS__REP, \
		   (translator_func) krb5_tgs_rep2KRB5_KDC__REP, \
		   (free_func) free_KRB5_TGS__REP)
#define decode_krb5_tgs_rep(req, output) \
    krb5_decode_generic(req, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_TGS__REP, \
		   (translator_func) KRB5_KDC__REP2krb5_tgs_rep, \
		   (free_func) free_KRB5_TGS__REP)

#define encode_krb5_ap_req(req, output) \
    krb5_encode_generic((krb5_const_pointer)req,  output, \
		   (encoder_func) encode_KRB5_AP__REQ, \
		   (translator_func) krb5_ap_req2KRB5_AP__REQ, \
		   (free_func) free_KRB5_AP__REQ)
#define decode_krb5_ap_req(req, output) \
    krb5_decode_generic(req, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_AP__REQ, \
		   (translator_func) KRB5_AP__REQ2krb5_ap_req, \
		   (free_func) free_KRB5_AP__REQ)

#define encode_krb5_ap_rep(reply, output) \
    krb5_encode_generic((krb5_const_pointer)reply, output, \
		   (encoder_func) encode_KRB5_AP__REP, \
		   (translator_func) krb5_ap_rep2KRB5_AP__REP, \
		   (free_func) free_KRB5_AP__REP)
#define decode_krb5_ap_rep(reply, output) \
    krb5_decode_generic(reply, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_AP__REP, \
		   (translator_func) KRB5_AP__REP2krb5_ap_rep, \
		   (free_func) free_KRB5_AP__REP)

#define encode_krb5_ap_rep_enc_part(rpart, output) \
    krb5_encode_generic((krb5_const_pointer)rpart, output, \
		   (encoder_func) encode_KRB5_EncAPRepPart, \
		   (translator_func) krb5_ap_rep_enc_part2KRB5_EncAPRepPart, \
		   (free_func) free_KRB5_EncAPRepPart)
#define decode_krb5_ap_rep_enc_part(rpart, output) \
    krb5_decode_generic(rpart, (krb5_pointer *) output, \
		    (decoder_func) decode_KRB5_EncAPRepPart, \
		    (translator_func) KRB5_EncAPRepPart2krb5_ap_rep_enc_part, \
		    (free_func) free_KRB5_EncAPRepPart)

#define encode_krb5_tgs_req(req, output) \
    krb5_encode_generic((krb5_const_pointer)req, output, \
		   (encoder_func) encode_KRB5_TGS__REQ, \
		   (translator_func) krb5_kdc_req2KRB5_TGS__REQ, \
		   (free_func) free_KRB5_TGS__REQ)
#define decode_krb5_tgs_req(req, output) \
    krb5_decode_generic(req, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_TGS__REQ, \
		   (translator_func) KRB5_TGS__REQ2krb5_kdc_req, \
		   (free_func) free_KRB5_TGS__REQ)

#define encode_krb5_kdc_req_body(req, output) \
    krb5_encode_generic((krb5_const_pointer)req, output, \
		   (encoder_func) encode_KRB5_KDC__REQ__BODY, \
		   (translator_func) krb5_kdc_req2KRB5_KDC__REQ__BODY, \
		   (free_func) free_KRB5_KDC__REQ__BODY)
#define decode_krb5_kdc_req_body(req, output) \
    krb5_decode_generic(req, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_TGS__REQ__BODY, \
		   (translator_func) KRB5_KDC__REQ__BODY2krb5_kdc_req, \
		   (free_func) free_KRB5_KDC__REQ__BODY)

#define encode_krb5_safe(req, output) \
    krb5_encode_generic((krb5_const_pointer)req, output, \
		   (encoder_func) encode_KRB5_KRB__SAFE, \
		   (translator_func) krb5_safe2KRB5_KRB__SAFE, \
		   (free_func) free_KRB5_KRB__SAFE)
#define decode_krb5_safe(req, output) \
    krb5_decode_generic(req, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_KRB__SAFE, \
		   (translator_func) KRB5_KRB__SAFE2krb5_safe, \
		   (free_func) free_KRB5_KRB__SAFE)

#define encode_krb5_priv(req, output) \
    krb5_encode_generic((krb5_const_pointer)req, output, \
		   (encoder_func) encode_KRB5_KRB__PRIV, \
		   (translator_func) krb5_priv2KRB5_KRB__PRIV, \
		   (free_func) free_KRB5_KRB__PRIV)
#define decode_krb5_priv(req, output) \
    krb5_decode_generic(req, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_KRB__PRIV, \
		   (translator_func) KRB5_KRB__PRIV2krb5_priv, \
		   (free_func) free_KRB5_KRB__PRIV)

#define encode_krb5_enc_priv_part(req, output) \
    krb5_encode_generic((krb5_const_pointer)req, output, \
		   (encoder_func) encode_KRB5_EncKrbPrivPart, \
		   (translator_func) krb5_priv_enc_part2KRB5_EncKrbPrivPart, \
		   (free_func) free_KRB5_EncKrbPrivPart)
#define decode_krb5_enc_priv_part(req, output) \
    krb5_decode_generic(req, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_EncKrbPrivPart, \
		   (translator_func) KRB5_EncKrbPrivPart2krb5_priv_enc_part, \
		   (free_func) free_KRB5_EncKrbPrivPart)

#define encode_krb5_error(req, output) \
    krb5_encode_generic((krb5_const_pointer)req, output, \
		   (encoder_func) encode_KRB5_KRB__ERROR, \
		   (translator_func) krb5_error2KRB5_KRB__ERROR, \
		   (free_func) free_KRB5_KRB__ERROR)
#define decode_krb5_error(req, output) \
    krb5_decode_generic(req, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_KRB__ERROR, \
		   (translator_func) KRB5_KRB__ERROR2krb5_error, \
		   (free_func) free_KRB5_KRB__ERROR)

#define encode_krb5_authdata(pauth, output) \
    krb5_encode_generic((krb5_const_pointer)pauth,  output, \
		   (encoder_func) encode_KRB5_AuthorizationData, \
		   (translator_func) krb5_authdata2KRB5_AuthorizationData, \
		   (free_func) free_KRB5_AuthorizationData)
#define decode_krb5_authdata(pauth, output) \
    krb5_decode_generic(pauth, (krb5_pointer *) output, \
		   (decoder_func) decode_KRB5_AuthorizationData, \
		   (translator_func) KRB5_AuthorizationData2krb5_authdata, \
		   (free_func) free_KRB5_AuthorizationData)

/* ASN.1 encoding knowledge; KEEP IN SYNC WITH ASN.1 defs! */
/* here we use some knowledge of ASN.1 encodings */
/* 
  Ticket is APPLICATION 1.
  Authenticator is APPLICATION 2.
  AS_REQ is APPLICATION 10.
  AS_REP is APPLICATION 11.
  TGS_REQ is APPLICATION 12.
  TGS_REP is APPLICATION 13.
  AP_REQ is APPLICATION 14.
  AP_REP is APPLICATION 15.
  KRB_SAFE is APPLICATION 20.
  KRB_PRIV is APPLICATION 21.
  EncASRepPart is APPLICATION 25.
  EncTGSRepPart is APPLICATION 26.
  EncAPRepPart is APPLICATION 27.
  EncKrbPrivPart is APPLICATION 28.
  KRB_ERROR is APPLICATION 30.
 */
/* allow either constructed or primitive encoding, so check for bit 6
   set or reset */
#define krb5_is_krb_ticket(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x61 ||\
				    (dat)->data[0] == 0x41))
#define krb5_is_krb_authenticator(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x62 ||\
				    (dat)->data[0] == 0x42))
#define krb5_is_as_req(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x6a ||\
				    (dat)->data[0] == 0x4a))
#define krb5_is_as_rep(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x6b ||\
				    (dat)->data[0] == 0x4b))
#define krb5_is_tgs_req(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x6c ||\
				    (dat)->data[0] == 0x4c))
#define krb5_is_tgs_rep(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x6d ||\
				    (dat)->data[0] == 0x4d))
#define krb5_is_ap_req(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x6e ||\
				    (dat)->data[0] == 0x4e))
#define krb5_is_ap_rep(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x6f ||\
				    (dat)->data[0] == 0x4f))
#define krb5_is_krb_safe(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x74 ||\
				    (dat)->data[0] == 0x54))
#define krb5_is_krb_priv(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x75 ||\
				    (dat)->data[0] == 0x55))
#define krb5_is_krb_enc_as_rep_part(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x79 ||\
				    (dat)->data[0] == 0x59))
#define krb5_is_krb_enc_tgs_rep_part(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x7a ||\
				    (dat)->data[0] == 0x5a))
#define krb5_is_krb_enc_ap_rep_part(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x7b ||\
				    (dat)->data[0] == 0x5b))
#define krb5_is_krb_enc_krb_priv_part(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x7c ||\
				    (dat)->data[0] == 0x5c))
#define krb5_is_krb_error(dat)\
	((dat) && (dat)->length && ((dat)->data[0] == 0x7e ||\
				    (dat)->data[0] == 0x5e))


#endif /* KRB5_ENCODE_DEFS__ */
