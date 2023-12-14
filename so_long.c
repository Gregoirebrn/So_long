#include "mlx.h"

typedef struct	s_data {
    void	*img;
    char	*addr;
    int		bits_per_pixel;
    int		line_length;
    int		endian;
}				t_data;


int	main(void)
{
    void	*mlx;
    void	*mlx_win;
    t_data	img;



    mlx = mlx_init();
    img.img = mlx_new_window(mlx, 1920, 1080, "so_long");
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
}