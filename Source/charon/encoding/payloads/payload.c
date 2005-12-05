/**
 * @file payload.c
 * 
 * @brief Generic payload interface
 * 
 * 
 */

/*
 * Copyright (C) 2005 Jan Hutter, Martin Willi
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */


#include "payload.h"

#include <encoding/payloads/ike_header.h>
#include <encoding/payloads/sa_payload.h>
#include <encoding/payloads/nonce_payload.h>
#include <encoding/payloads/id_payload.h>
#include <encoding/payloads/ke_payload.h>
#include <encoding/payloads/notify_payload.h>
#include <encoding/payloads/auth_payload.h>
#include <encoding/payloads/cert_payload.h>
#include <encoding/payloads/encryption_payload.h>
#include <encoding/payloads/ts_payload.h>

/*
 * build the mappings for payload_type_t
 */
mapping_t payload_type_m[] = {
	{NO_PAYLOAD, "NO_PAYLOAD"},
	{SECURITY_ASSOCIATION, "SECURITY_ASSOCIATION"},
	{KEY_EXCHANGE, "KEY_EXCHANGE"},
	{ID_INITIATOR, "ID_INITIATOR"},
	{ID_RESPONDER, "ID_RESPONDER"},
	{CERTIFICATE, "CERTIFICATE"},
	{CERTIFICATE_REQUEST, "CERTIFICATE_REQUEST"},
	{AUTHENTICATION, "AUTHENTICATION"},
	{NONCE, "NONCE"},
	{NOTIFY, "NOTIFY"},
	{DELETE, "DELETE"},
	{VENDOR_ID, "VENDOR_ID"},
	{TRAFFIC_SELECTOR_INITIATOR, "TRAFFIC_SELECTOR_INITIATOR"},
	{TRAFFIC_SELECTOR_RESPONDER, "TRAFFIC_SELECTOR_RESPONDER"},
	{ENCRYPTED, "ENCRYPTED"},
	{CONFIGURATION, "CONFIGURATION"},
	{EXTENSIBLE_AUTHENTICATION, "EXTENSIBLE_AUTHENTICATION"},
	{HEADER, "HEADER"},
	{PROPOSAL_SUBSTRUCTURE, "PROPOSAL_SUBSTRUCTURE"},
	{TRANSFORM_SUBSTRUCTURE, "TRANSFORM_SUBSTRUCTURE"},
	{TRANSFORM_ATTRIBUTE, "TRANSFORM_ATTRIBUTE"},
	{TRAFFIC_SELECTOR_SUBSTRUCTURE, "TRAFFIC_SELECTOR_SUBSTRUCTURE"},
	{MAPPING_END, NULL}
};

/*
 * see header
 */
payload_t *payload_create(payload_type_t type)
{
	switch (type)
	{
		case HEADER:
			return (payload_t*)ike_header_create();
		case SECURITY_ASSOCIATION:
			return (payload_t*)sa_payload_create();
		case PROPOSAL_SUBSTRUCTURE:
			return (payload_t*)proposal_substructure_create();
		case TRANSFORM_SUBSTRUCTURE:
			return (payload_t*)transform_substructure_create();
		case TRANSFORM_ATTRIBUTE:
			return (payload_t*)transform_attribute_create();
		case NONCE:
			return (payload_t*)nonce_payload_create();
		case ID_INITIATOR:
			return (payload_t*)id_payload_create(TRUE);
		case ID_RESPONDER:
			return (payload_t*)id_payload_create(FALSE);
		case AUTHENTICATION:
			return (payload_t*)auth_payload_create();
		case CERTIFICATE:
			return (payload_t*)cert_payload_create();
		case TRAFFIC_SELECTOR_SUBSTRUCTURE:
			return (payload_t*)traffic_selector_substructure_create();
		case TRAFFIC_SELECTOR_INITIATOR:
			return (payload_t*)ts_payload_create(TRUE);
		case TRAFFIC_SELECTOR_RESPONDER:
			return (payload_t*)ts_payload_create(FALSE);
		case KEY_EXCHANGE:
			return (payload_t*)ke_payload_create();
		case NOTIFY:
			return (payload_t*)notify_payload_create();
		case ENCRYPTED:
			return (payload_t*)encryption_payload_create();
		default:
			return NULL;
	}
}

