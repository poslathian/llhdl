#ifndef __TILM_TILM_H
#define __TILM_TILM_H

#include <gmp.h>

#include <llhdl/structure.h>
#include <mapkit/mapkit.h>

enum {
	TILM_SHANNON = 0,
	TILM_BDSPGA,
	TILM_COUNT /* must be last */
};

#define TILM_DEFAULT TILM_SHANNON

struct tilm_desc {
	const char *handle;
	const char *description;
};

extern struct tilm_desc tilm_mappers[];

int tilm_get_mapper_by_handle(const char *handle);

/* Create a net and return a opaque handle
 *   <user> User pointer from the tilm_sc structure
 */
typedef void * (*tilm_create_net_c)(void *user);

/* Create a LUT and return a opaque instance handle
 *  <inputs> Number of inputs
 *  <contents> Bitmap of the LUT contents
 *  <user> User pointer from the tilm_sc structure
 */
typedef void * (*tilm_create_lut_c)(int inputs, mpz_t contents, void *user);

/* Create a 2-mux and return a opaque instance handle
 *  <muxlevel> Number of muxes before this one
 *  <user> User pointer from the tilm_sc structure
 * If this callback is not provided, of if it returns NULL,
 * the multiplexer will be implemented with a LUT.
 */
typedef void * (*tilm_create_mux_c)(int muxlevel, void *user);

void tilm_register(struct mapkit_sc *mapkit,
	int mapper_id,
	int max_inputs,
	void *extra_mapper_param,
	tilm_create_net_c create_net,
	tilm_create_lut_c create_lut,
	tilm_create_mux_c create_mux,
	void *user);

#endif /* __TILM_TILM_H */

