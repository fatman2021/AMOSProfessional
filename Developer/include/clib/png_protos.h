#ifndef CLIB_PNG_PROTOS_H
#define CLIB_PNG_PROTOS_H

/*
    *** Automatically generated from '/home/vsts/work/1/s/workbench/libs/png/png.conf'. Edits will be lost. ***
    Copyright � 1995-2019, The AROS Development Team. All rights reserved.
*/

#include <aros/libcall.h>

#include <png.h>

__BEGIN_DECLS


#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_build_grayscale_palette
void png_build_grayscale_palette(int bit_depth, png_colorp palette);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_chunk_error
PNG_NORETURN void png_chunk_error(png_const_structrp png_ptr, png_const_charp error_message);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_chunk_warning
void png_chunk_warning(png_const_structrp png_ptr, png_const_charp warning_message);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_convert_from_struct_tm
void png_convert_from_struct_tm(png_timep ptime, const struct tm * ttime);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_convert_from_time_t
void png_convert_from_time_t(png_timep ptime, time_t ttime);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_create_info_struct
PNG_ALLOCATED png_infop png_create_info_struct(png_const_structrp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_create_read_struct
PNG_ALLOCATED png_structp png_create_read_struct(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_create_write_struct
PNG_ALLOCATED png_structp png_create_write_struct(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_data_freer
void png_data_freer(png_const_structrp png_ptr, png_inforp info_ptr, int freer, png_uint_32 mask);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_destroy_info_struct
void png_destroy_info_struct(png_const_structrp png_ptr, png_infopp info_ptr_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_destroy_read_struct
void png_destroy_read_struct(png_structpp png_ptr_ptr, png_infopp info_ptr_ptr, png_infopp end_info_ptr_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_destroy_write_struct
void png_destroy_write_struct(png_structpp png_ptr_ptr, png_infopp info_ptr_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_error
PNG_NORETURN void png_error(png_const_structrp png_ptr, png_const_charp error_message);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_free
void png_free(png_const_structrp png_ptr, png_voidp ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_free_data
void png_free_data(png_const_structrp png_ptr, png_inforp info_ptr, png_uint_32 free_me, int num);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_IHDR
png_uint_32 png_get_IHDR(png_const_structrp png_ptr, png_const_inforp info_ptr, png_uint_32 *width, png_uint_32 *height, int *bit_depth, int *color_type, int *interlace_method, int *compression_method, int *filter_method);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_PLTE
png_uint_32 png_get_PLTE(png_const_structrp png_ptr, png_inforp info_ptr, png_colorp *palette, int *num_palette);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_bKGD
png_uint_32 png_get_bKGD(png_const_structp png_ptr, png_infop info_ptr, png_color_16p *background);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_bit_depth
png_byte png_get_bit_depth(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_cHRM
png_uint_32 png_get_cHRM(png_const_structp png_ptr, png_const_infop info_ptr, double *white_x, double *white_y, double *red_x, double *red_y, double *green_x, double *green_y, double *blue_x, double *blue_y);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_cHRM_fixed
png_uint_32 png_get_cHRM_fixed(png_const_structp png_ptr, png_const_infop info_ptr, png_fixed_point *int_white_x, png_fixed_point *int_white_y, png_fixed_point *int_red_x, png_fixed_point *int_red_y, png_fixed_point *int_green_x, png_fixed_point *int_green_y, png_fixed_point *int_blue_x, png_fixed_point *int_blue_y);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_channels
png_byte png_get_channels(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_color_type
png_byte png_get_color_type(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_compression_buffer_size
png_size_t png_get_compression_buffer_size(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_compression_type
png_byte png_get_compression_type(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_copyright
png_const_charp png_get_copyright(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_error_ptr
png_voidp png_get_error_ptr(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_filter_type
png_byte png_get_filter_type(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_gAMA
png_uint_32 png_get_gAMA(png_const_structp png_ptr, png_const_infop info_ptr, double *file_gamma);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_gAMA_fixed
png_uint_32 png_get_gAMA_fixed(png_const_structp png_ptr, png_const_infop info_ptr, png_fixed_point *int_file_gamma);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_hIST
png_uint_32 png_get_hIST(png_const_structrp png_ptr, png_inforp info_ptr, png_uint_16p *hist);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_header_ver
png_const_charp png_get_header_ver(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_header_version
png_const_charp png_get_header_version(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_iCCP
png_uint_32 png_get_iCCP(png_const_structrp png_ptr, png_inforp info_ptr, png_charpp name, int *compression_type, png_bytepp profile, png_uint_32 *proflen);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_image_height
png_uint_32 png_get_image_height(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_image_width
png_uint_32 png_get_image_width(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_interlace_type
png_byte png_get_interlace_type(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_io_ptr
png_voidp png_get_io_ptr(png_const_structrp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_libpng_ver
png_const_charp png_get_libpng_ver(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_oFFs
png_uint_32 png_get_oFFs(png_const_structp png_ptr, png_const_infop info_ptr, png_int_32 *offset_x, png_int_32 *offset_y, int *unit_type);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_pCAL
png_uint_32 png_get_pCAL(png_const_structrp png_ptr, png_inforp info_ptr, png_charp *purpose, png_int_32 *X0, png_int_32 *X1, int *type, int *nparams, png_charp *units, png_charpp *params);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_pHYs
png_uint_32 png_get_pHYs(png_const_structp png_ptr, png_const_infop info_ptr, png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_pixel_aspect_ratio
float png_get_pixel_aspect_ratio(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_pixels_per_meter
png_uint_32 png_get_pixels_per_meter(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_progressive_ptr
png_voidp png_get_progressive_ptr(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_rgb_to_gray_status
png_byte png_get_rgb_to_gray_status(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_rowbytes
png_size_t png_get_rowbytes(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_rows
png_bytepp png_get_rows(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_sBIT
png_uint_32 png_get_sBIT(png_const_structp png_ptr, png_infop info_ptr, png_color_8p *sig_bit);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_sCAL
png_uint_32 png_get_sCAL(png_const_structp png_ptr, png_const_infop info_ptr, int *unit, double *width, double *height);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_sPLT
int png_get_sPLT(png_const_structrp png_ptr, png_inforp info_ptr, png_sPLT_tpp entries);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_sRGB
png_uint_32 png_get_sRGB(png_const_structrp png_ptr, png_const_inforp info_ptr, int *file_srgb_intent);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_signature
png_const_bytep png_get_signature(png_const_structrp png_ptr, png_const_inforp info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_tIME
png_uint_32 png_get_tIME(png_const_structp png_ptr, png_infop info_ptr, png_timep *mod_time);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_tRNS
png_uint_32 png_get_tRNS(png_const_structrp png_ptr, png_inforp info_ptr, png_bytep *trans_alpha, int *num_trans, png_color_16p *trans_color);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_text
int png_get_text(png_const_structrp png_ptr, png_inforp info_ptr, png_textp *text_ptr, int *num_text);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_unknown_chunks
int png_get_unknown_chunks(png_const_structrp png_ptr, png_inforp info_ptr, png_unknown_chunkpp entries);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_user_chunk_ptr
png_voidp png_get_user_chunk_ptr(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_user_transform_ptr
png_voidp png_get_user_transform_ptr(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_valid
png_uint_32 png_get_valid(png_const_structp png_ptr, png_const_infop info_ptr, png_uint_32 flag);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_x_offset_microns
png_int_32 png_get_x_offset_microns(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_x_offset_pixels
png_int_32 png_get_x_offset_pixels(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_x_pixels_per_meter
png_uint_32 png_get_x_pixels_per_meter(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_y_offset_microns
png_int_32 png_get_y_offset_microns(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_y_offset_pixels
png_int_32 png_get_y_offset_pixels(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_y_pixels_per_meter
png_uint_32 png_get_y_pixels_per_meter(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_malloc
PNG_ALLOCATED png_voidp png_malloc(png_const_structrp png_ptr, png_alloc_size_t size);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_process_data
void png_process_data(png_structp png_ptr, png_infop info_ptr, png_bytep buffer, png_size_t buffer_size);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_progressive_combine_row
void png_progressive_combine_row(png_const_structrp png_ptr, png_bytep old_row, png_const_bytep new_row);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_read_end
void png_read_end(png_structp png_ptr, png_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_read_image
void png_read_image(png_structp png_ptr, png_bytepp image);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_read_info
void png_read_info(png_structp png_ptr, png_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_read_png
void png_read_png(png_structp png_ptr, png_infop info_ptr, int transforms, png_voidp params);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_read_row
void png_read_row(png_structp png_ptr, png_bytep row, png_bytep display_row);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_read_rows
void png_read_rows(png_structp png_ptr, png_bytepp row, png_bytepp display_row, png_uint_32 num_rows);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_read_update_info
void png_read_update_info(png_structp png_ptr, png_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_reset_zstream
int png_reset_zstream(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_IHDR
void png_set_IHDR(png_const_structrp png_ptr, png_inforp info_ptr, png_uint_32 width, png_uint_32 height, int bit_depth, int color_type, int interlace_method, int compression_method, int filter_method);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_PLTE
void png_set_PLTE(png_structp png_ptr, png_infop info_ptr, png_const_colorp palette, int num_palette);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_bKGD
void png_set_bKGD(png_const_structrp png_ptr, png_inforp info_ptr, png_const_color_16p background);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_background
void png_set_background(png_structp png_ptr, png_const_color_16p background_color, int background_gamma_code, int need_expand, double background_gamma);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_bgr
void png_set_bgr(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_cHRM
void png_set_cHRM(png_const_structrp png_ptr, png_inforp info_ptr, double white_x, double white_y, double red_x, double red_y, double green_x, double green_y, double blue_x, double blue_y);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_cHRM_fixed
void png_set_cHRM_fixed(png_const_structrp png_ptr, png_inforp info_ptr, png_fixed_point int_white_x, png_fixed_point int_white_y, png_fixed_point int_red_x, png_fixed_point int_red_y, png_fixed_point int_green_x, png_fixed_point int_green_y, png_fixed_point int_blue_x, png_fixed_point int_blue_y);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_compression_buffer_size
void png_set_compression_buffer_size(png_structp png_ptr, png_size_t size);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_compression_level
void png_set_compression_level(png_structp png_ptr, int level);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_compression_mem_level
void png_set_compression_mem_level(png_structp png_ptr, int mem_level);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_compression_method
void png_set_compression_method(png_structp png_ptr, int method);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_compression_strategy
void png_set_compression_strategy(png_structp png_ptr, int strategy);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_compression_window_bits
void png_set_compression_window_bits(png_structp png_ptr, int window_bits);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_crc_action
void png_set_crc_action(png_structp png_ptr, int crit_action, int ancil_action);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_quantize
void png_set_quantize(png_structp png_ptr, png_colorp palette, int num_palette, int maximum_colors, png_const_uint_16p histogram, int full_quantize);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_error_fn
void png_set_error_fn(png_structp png_ptr, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warning_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_expand
void png_set_expand(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_filler
void png_set_filler(png_structp png_ptr, png_uint_32 filler, int flags);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_filter
void png_set_filter(png_structp png_ptr, int method, int filters);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_filter_heuristics
void png_set_filter_heuristics(png_structp png_ptr, int heuristic_method, int num_weights, png_const_doublep filter_weights, png_const_doublep filter_costs);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_flush
void png_set_flush(png_structp png_ptr, int nrows);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_gAMA
void png_set_gAMA(png_const_structrp png_ptr, png_inforp info_ptr, double file_gamma);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_gAMA_fixed
void png_set_gAMA_fixed(png_const_structrp png_ptr, png_inforp info_ptr, png_fixed_point int_file_gamma);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_gamma
void png_set_gamma(png_structp png_ptr, double screen_gamma, double override_file_gamma);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_gray_to_rgb
void png_set_gray_to_rgb(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_hIST
void png_set_hIST(png_const_structrp png_ptr, png_inforp info_ptr, png_const_uint_16p hist);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_iCCP
void png_set_iCCP(png_const_structrp png_ptr, png_inforp info_ptr, png_const_charp name, int compression_type, png_const_bytep profile, png_uint_32 proflen);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_interlace_handling
int png_set_interlace_handling(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_invert_alpha
void png_set_invert_alpha(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_invert_mono
void png_set_invert_mono(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_keep_unknown_chunks
void png_set_keep_unknown_chunks(png_structp png_ptr, int keep, png_const_bytep chunk_list, int num_chunks);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_oFFs
void png_set_oFFs(png_const_structrp png_ptr, png_inforp info_ptr, png_int_32 offset_x, png_int_32 offset_y, int unit_type);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_pCAL
void png_set_pCAL(png_const_structrp png_ptr, png_inforp info_ptr, png_const_charp purpose, png_int_32 X0, png_int_32 X1, int type, int nparams, png_const_charp units, png_charpp params);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_pHYs
void png_set_pHYs(png_const_structrp png_ptr, png_inforp info_ptr, png_uint_32 res_x, png_uint_32 res_y, int unit_type);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_packing
void png_set_packing(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_packswap
void png_set_packswap(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_palette_to_rgb
void png_set_palette_to_rgb(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_progressive_read_fn
void png_set_progressive_read_fn(png_structp png_ptr, png_voidp progressive_ptr, png_progressive_info_ptr info_fn, png_progressive_row_ptr row_fn, png_progressive_end_ptr end_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_read_fn
void png_set_read_fn(png_structp png_ptr, png_voidp io_ptr, png_rw_ptr read_data_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_read_status_fn
void png_set_read_status_fn(png_structp png_ptr, png_read_status_ptr read_row_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_read_user_chunk_fn
void png_set_read_user_chunk_fn(png_structp png_ptr, png_voidp user_chunk_ptr, png_user_chunk_ptr read_user_chunk_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_read_user_transform_fn
void png_set_read_user_transform_fn(png_structp png_ptr, png_user_transform_ptr read_user_transform_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_rgb_to_gray
void png_set_rgb_to_gray(png_structp png_ptr, int error_action, double red, double green);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_rgb_to_gray_fixed
void png_set_rgb_to_gray_fixed(png_structp png_ptr, int error_action, png_fixed_point red, png_fixed_point green);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_rows
void png_set_rows(png_const_structrp png_ptr, png_inforp info_ptr, png_bytepp row_pointers);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_sBIT
void png_set_sBIT(png_const_structrp png_ptr, png_inforp info_ptr, png_const_color_8p sig_bit);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_sCAL
void png_set_sCAL(png_const_structrp png_ptr, png_inforp info_ptr, int unit, double width, double height);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_sPLT
void png_set_sPLT(png_const_structrp png_ptr, png_inforp info_ptr, png_const_sPLT_tp entries, int nentries);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_sRGB
void png_set_sRGB(png_const_structrp png_ptr, png_inforp info_ptr, int srgb_intent);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_sRGB_gAMA_and_cHRM
void png_set_sRGB_gAMA_and_cHRM(png_const_structrp png_ptr, png_inforp info_ptr, int srgb_intent);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_shift
void png_set_shift(png_structp png_ptr, png_const_color_8p true_bits);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_sig_bytes
void png_set_sig_bytes(png_structp png_ptr, int num_bytes);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_strip_16
void png_set_strip_16(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_strip_alpha
void png_set_strip_alpha(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_swap
void png_set_swap(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_swap_alpha
void png_set_swap_alpha(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_tIME
void png_set_tIME(png_const_structrp png_ptr, png_inforp info_ptr, png_const_timep mod_time);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_tRNS
void png_set_tRNS(png_structp png_ptr, png_infop info_ptr, png_const_bytep trans_alpha, int num_trans, png_const_color_16p trans_color);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_tRNS_to_alpha
void png_set_tRNS_to_alpha(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_text
void png_set_text(png_const_structrp png_ptr, png_inforp info_ptr, png_const_textp text_ptr, int num_text);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_unknown_chunk_location
void png_set_unknown_chunk_location(png_const_structrp png_ptr, png_inforp info_ptr, int chunk, int location);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_unknown_chunks
void png_set_unknown_chunks(png_const_structrp png_ptr, png_inforp info_ptr, png_const_unknown_chunkp unknowns, int num_unknowns);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_user_transform_info
void png_set_user_transform_info(png_structp png_ptr, png_voidp user_transform_ptr, int user_transform_depth, int user_transform_channels);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_write_fn
void png_set_write_fn(png_structp png_ptr, png_voidp io_ptr, png_rw_ptr write_data_fn, png_flush_ptr output_flush_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_write_status_fn
void png_set_write_status_fn(png_structp png_ptr, png_write_status_ptr write_row_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_write_user_transform_fn
void png_set_write_user_transform_fn(png_structp png_ptr, png_user_transform_ptr write_user_transform_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_sig_cmp
int png_sig_cmp(png_const_bytep sig, png_size_t start, png_size_t num_to_check);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_start_read_image
void png_start_read_image(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_warning
void png_warning(png_const_structrp png_ptr, png_const_charp warning_message);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_chunk
void png_write_chunk(png_structp png_ptr, png_const_bytep chunk_name, png_const_bytep data, png_size_t length);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_chunk_data
void png_write_chunk_data(png_structp png_ptr, png_const_bytep data, png_size_t length);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_chunk_end
void png_write_chunk_end(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_chunk_start
void png_write_chunk_start(png_structp png_ptr, png_const_bytep chunk_name, png_uint_32 length);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_end
void png_write_end(png_structp png_ptr, png_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_flush
void png_write_flush(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_image
void png_write_image(png_structp png_ptr, png_bytepp image);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_info
void png_write_info(png_structrp png_ptr, png_const_inforp info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_info_before_PLTE
void png_write_info_before_PLTE(png_structrp png_ptr, png_const_inforp info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_png
void png_write_png(png_structp png_ptr, png_infop info_ptr, int transforms, png_voidp params);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_row
void png_write_row(png_structp png_ptr, png_const_bytep row);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_write_rows
void png_write_rows(png_structp png_ptr, png_bytepp row, png_uint_32 num_rows);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_access_version_number
png_uint_32 png_access_version_number(void);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_convert_to_rfc1123
png_const_charp png_convert_to_rfc1123(png_structp png_ptr, png_const_timep ptime);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_invalid
void png_set_invalid(png_const_structrp png_ptr, png_inforp info_ptr, int mask);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_permit_mng_features
png_uint_32 png_permit_mng_features(png_structp png_ptr, png_uint_32 mng_features_permitted);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_strip_error_numbers
void png_set_strip_error_numbers(png_structp png_ptr, png_uint_32 strip_mode);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_handle_as_unknown
int png_handle_as_unknown(png_const_structrp png_ptr, png_const_bytep chunk_name);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_malloc_warn
PNG_ALLOCATED png_voidp png_malloc_warn(png_const_structrp png_ptr, png_alloc_size_t size);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_mem_fn
void png_set_mem_fn(png_structp png_ptr, png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_mem_ptr
png_voidp png_get_mem_ptr(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_create_read_struct_2
PNG_ALLOCATED png_structp png_create_read_struct_2(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_create_write_struct_2
PNG_ALLOCATED png_structp png_create_write_struct_2(png_const_charp user_png_ver, png_voidp error_ptr, png_error_ptr error_fn, png_error_ptr warn_fn, png_voidp mem_ptr, png_malloc_ptr malloc_fn, png_free_ptr free_fn);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_malloc_default
PNG_ALLOCATED png_voidp png_malloc_default(png_const_structrp png_ptr, png_alloc_size_t size);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_free_default
void png_free_default(png_const_structrp png_ptr, png_voidp ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_user_limits
void png_set_user_limits(png_structp png_ptr, png_uint_32 user_width_max, png_uint_32 user_height_max);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_user_width_max
png_uint_32 png_get_user_width_max(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_get_user_height_max
png_uint_32 png_get_user_height_max(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_add_alpha
void png_set_add_alpha(png_structp png_ptr, png_uint_32 filler, int flags);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__)
#ifndef png_set_expand_gray_1_2_4_to_8
void png_set_expand_gray_1_2_4_to_8(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (0 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_longjmp_fn
jmp_buf* png_set_longjmp_fn(png_structp png_ptr, png_longjmp_ptr longjmp_fn, size_t jmp_buf_size);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_longjmp
PNG_NORETURN void png_longjmp(png_const_structrp png_ptr, int val);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_write_sig
void png_write_sig(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_info_init_3
void png_info_init_3(png_infopp info_ptr, png_size_t png_info_struct_size);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_init_io
void png_init_io(png_structp png_ptr, png_FILE_p fp);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_calloc
PNG_ALLOCATED png_voidp png_calloc(png_const_structrp png_ptr, png_alloc_size_t size);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_benign_error
void png_benign_error(png_const_structrp png_ptr, png_const_charp warning_message);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_chunk_benign_error
void png_chunk_benign_error(png_const_structrp png_ptr, png_const_charp warning_message);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_benign_errors
void png_set_benign_errors(png_structp png_ptr, int allowed);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_sCAL_s
png_uint_32 png_get_sCAL_s(png_const_structp png_ptr, png_const_infop info_ptr, int *unit, png_charpp swidth, png_charpp sheight);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_sCAL_s
void png_set_sCAL_s(png_const_structrp png_ptr, png_inforp info_ptr, int unit, png_const_charp swidth, png_const_charp sheight);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_chunk_cache_max
void png_set_chunk_cache_max(png_structp png_ptr, png_uint_32 user_chunk_cache_max);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_chunk_cache_max
png_uint_32 png_get_chunk_cache_max(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_chunk_malloc_max
void png_set_chunk_malloc_max(png_structp png_ptr, png_alloc_size_t user_chunk_cache_max);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_chunk_malloc_max
png_alloc_size_t png_get_chunk_malloc_max(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_pixels_per_inch
png_uint_32 png_get_pixels_per_inch(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_x_pixels_per_inch
png_uint_32 png_get_x_pixels_per_inch(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_y_pixels_per_inch
png_uint_32 png_get_y_pixels_per_inch(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_x_offset_inches
float png_get_x_offset_inches(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_y_offset_inches
float png_get_y_offset_inches(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_pHYs_dpi
png_uint_32 png_get_pHYs_dpi(png_const_structp png_ptr, png_const_infop info_ptr, png_uint_32 *res_x, png_uint_32 *res_y, int *unit_type);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_io_state
png_uint_32 png_get_io_state(png_const_structrp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_uint_31
png_uint_32 png_get_uint_31(png_const_structrp png_ptr, png_const_bytep buf);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_save_uint_32
void png_save_uint_32(png_bytep buf, png_uint_32 i);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_save_int_32
void png_save_int_32(png_bytep buf, png_int_32 i);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_save_uint_16
void png_save_uint_16(png_bytep buf, unsigned int i);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_gamma_fixed
void png_set_gamma_fixed(png_structp png_ptr, png_fixed_point screen_gamma, png_fixed_point override_file_gamma);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_filter_heuristics_fixed
void png_set_filter_heuristics_fixed(png_structp png_ptr, int heuristic_method, int num_weights, png_const_fixed_point_p filter_weights, png_const_fixed_point_p filter_costs);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_pixel_aspect_ratio_fixed
png_fixed_point png_get_pixel_aspect_ratio_fixed(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_x_offset_inches_fixed
png_fixed_point png_get_x_offset_inches_fixed(png_const_structrp png_ptr, png_const_inforp info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_y_offset_inches_fixed
png_fixed_point png_get_y_offset_inches_fixed(png_const_structrp png_ptr, png_const_inforp info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_sCAL_fixed
void png_set_sCAL_fixed(png_const_structrp png_ptr, png_inforp info_ptr, int unit, png_fixed_point width, png_fixed_point height);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_sCAL_fixed
png_uint_32 png_get_sCAL_fixed(png_const_structrp png_ptr, png_const_inforp info_ptr, int *unit, png_fixed_point *width, png_fixed_point *height);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_background_fixed
void png_set_background_fixed(png_structp png_ptr, png_const_color_16p background_color, int background_gamma_code, int need_expand, png_fixed_point background_gamma);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_io_chunk_type
png_uint_32 png_get_io_chunk_type(png_const_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_current_row_number
png_uint_32 png_get_current_row_number(png_const_structp);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_current_pass_number
png_byte png_get_current_pass_number(png_const_structp);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_process_data_pause
png_size_t png_process_data_pause(png_structp, int save);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_process_data_skip
png_uint_32 png_process_data_skip(png_structp);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_expand_16
void png_set_expand_16(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_text_compression_level
void png_set_text_compression_level(png_structp png_ptr, int level);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_text_compression_mem_level
void png_set_text_compression_mem_level(png_structp png_ptr, int mem_level);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_text_compression_strategy
void png_set_text_compression_strategy(png_structp png_ptr, int strategy);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_text_compression_window_bits
void png_set_text_compression_window_bits(png_structp png_ptr, int window_bits);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_text_compression_method
void png_set_text_compression_method(png_structp png_ptr, int method);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_alpha_mode
void png_set_alpha_mode(png_structp png_ptr, int mode, double output_gamma);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_alpha_mode_fixed
void png_set_alpha_mode_fixed(png_structp png_ptr, int mode, png_fixed_point output_gamma);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_scale_16
void png_set_scale_16(png_structp png_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_cHRM_XYZ
png_uint_32 png_get_cHRM_XYZ(png_const_structrp png_ptr, png_const_inforp info_ptr, double *red_X, double *red_Y, double *red_Z, double *green_X, double *green_Y, double *green_Z, double *blue_X, double *blue_Y, double *blue_Z);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_cHRM_XYZ_fixed
png_uint_32 png_get_cHRM_XYZ_fixed(png_const_structrp png_ptr, png_const_inforp info_ptr, png_fixed_point *int_red_X, png_fixed_point *int_red_Y, png_fixed_point *int_red_Z, png_fixed_point *int_green_X, png_fixed_point *int_green_Y, png_fixed_point *int_green_Z, png_fixed_point *int_blue_X, png_fixed_point *int_blue_Y, png_fixed_point *int_blue_Z);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_cHRM_XYZ
void png_set_cHRM_XYZ(png_const_structrp png_ptr, png_inforp info_ptr, double red_X, double red_Y, double red_Z, double green_X, double green_Y, double green_Z, double blue_X, double blue_Y, double blue_Z);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_cHRM_XYZ_fixed
void png_set_cHRM_XYZ_fixed(png_const_structrp png_ptr, png_inforp info_ptr, png_fixed_point int_red_X, png_fixed_point int_red_Y, png_fixed_point int_red_Z, png_fixed_point int_green_X, png_fixed_point int_green_Y, png_fixed_point int_green_Z, png_fixed_point int_blue_X, png_fixed_point int_blue_Y, png_fixed_point int_blue_Z);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_image_begin_read_from_file
int png_image_begin_read_from_file(png_imagep image, const char *file_name);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_image_begin_read_from_stdio
int png_image_begin_read_from_stdio(png_imagep image, FILE* file);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_image_begin_read_from_memory
int png_image_begin_read_from_memory(png_imagep image, png_const_voidp memory, png_size_t size);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_image_finish_read
int png_image_finish_read(png_imagep image, png_const_colorp background, void *buffer, png_int_32 row_stride, void *colormap);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_image_free
void png_image_free(png_imagep image);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_image_write_to_file
int png_image_write_to_file(png_imagep image, const char *file, int convert_to_8bit, const void *buffer, png_int_32 row_stride, const void *colormap);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_image_write_to_stdio
int png_image_write_to_stdio(png_imagep image, FILE *file, int convert_to_8_bit, const void *buffer, png_int_32 row_stride, const void *colormap);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_convert_to_rfc1123_buffer
int png_convert_to_rfc1123_buffer(char out[29], png_const_timep ptime);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_check_for_invalid_index
void png_set_check_for_invalid_index(png_structp png_ptr, int allowed);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_get_palette_max
int png_get_palette_max(png_const_structp png_ptr, png_const_infop info_ptr);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__)
#ifndef png_set_option
int png_set_option(png_structrp png_ptr, int option, int onoff);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (52 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (53 <= __PNG_LIBAPI__)
#ifndef png_set_eXIf
void png_set_eXIf(png_struct const* png_ptr, png_info* info_ptr, png_bytep const eXIf_buf);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (53 <= __PNG_LIBAPI__) */

#if !defined(__PNG_LIBAPI__) || (53 <= __PNG_LIBAPI__)
#ifndef png_set_eXIf_1
void png_set_eXIf_1(png_struct const* png_ptr, png_info* info_ptr, png_uint_32 const num_exif, png_bytep const eXIf_buf);
#endif

#endif /* !defined(__PNG_LIBAPI__) || (53 <= __PNG_LIBAPI__) */

__END_DECLS

#endif /* CLIB_PNG_PROTOS_H */
