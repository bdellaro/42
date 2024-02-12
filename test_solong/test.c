#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include "MLX42/include/MLX42/MLX42.h"
#define WIDTH 720
#define HEIGHT 480

void my_keyhook(mlx_key_data_t keydata, void *keys)
{
	printf(" KEEEEEY ; %s", (char*)keys);
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
		puts("Hello ");

	// If we RELEASE the 'K' key, print "World".
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");

	// If we HOLD the 'L' key, print "!".
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
}

int32_t	main(void)
{
	mlx_t* mlx;
	keys_t	keys;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);

	mlx_key_hook(mlx, &my_keyhook, &keys);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
