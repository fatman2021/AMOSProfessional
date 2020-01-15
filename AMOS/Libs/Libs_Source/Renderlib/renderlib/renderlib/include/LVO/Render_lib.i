	IFND	LIBRARIES_RENDER_LIB_I
LIBRARIES_RENDER_LIB_I	SET	1
**
**	$VER: render_lib.i v27.0 (15.8.97)
**
**	render.library vector offsets
**
**	© TEK neoscientists
**

	IFND    EXEC_LIBRARIES_I
	include "exec/libraries.i"
	ENDC

;==========================================================================
;===========================  LVO DEFINITIONS  ============================
;==========================================================================

	LIBINIT
	LIBDEF		_LVOTurboFillMem		; strictly private
	LIBDEF		_LVOTurboCopyMem		; strictly private
	LIBDEF		_LVOCreateRMHandlerA
	LIBDEF		_LVODeleteRMHandler
	LIBDEF		_LVOAllocRenderMem
	LIBDEF		_LVOFreeRenderMem
	LIBDEF		_LVOAllocRenderVec
	LIBDEF		_LVOFreeRenderVec
	LIBDEF		_LVOCreateHistogramA
	LIBDEF		_LVODeleteHistogram
	LIBDEF		_LVOQueryHistogram
	LIBDEF		_LVOAddRGB
	LIBDEF		_LVOAddRGBImageA
	LIBDEF		_LVOAddChunkyImageA
	LIBDEF		_LVOExtractPaletteA
	LIBDEF		_LVORenderA
	LIBDEF		_LVOPlanar2Chunky
	LIBDEF		_LVOChunky2RGBA
	LIBDEF		_LVOChunky2BitMapA
	LIBDEF		_LVOCreateScaleEngineA
	LIBDEF		_LVODeleteScaleEngine
	LIBDEF		_LVOScaleA
	LIBDEF		_LVOConvertChunkyA
	LIBDEF		_LVOCreatePenTableA
	LIBDEF		_LVOCreatePaletteA
	LIBDEF		_LVODeletePalette
	LIBDEF		_LVOImportPaletteA
	LIBDEF		_LVOExportPaletteA
	LIBDEF		_LVOCountRGB
	LIBDEF		_LVOBestPen
	LIBDEF		_LVOFlushPalette
	LIBDEF		_LVOSortPaletteA
	LIBDEF		_LVOAddHistogramA
	LIBDEF		_LVOScaleOrdinate
	LIBDEF		_LVOCreateHistogramPointerArray	; strictly private
	LIBDEF		_LVOCountHistogram		; strictly private
	LIBDEF		_LVOCreateMapEngineA
	LIBDEF		_LVODeleteMapEngine
	LIBDEF		_LVOMapRGBArrayA
	LIBDEF		_LVORGBArrayDiversityA
	LIBDEF		_LVOChunkyArrayDiversityA
	LIBDEF		_LVOMapChunkyArrayA
	LIBDEF		_LVOInsertAlphaChannelA
	LIBDEF		_LVOExtractAlphaChannelA
	LIBDEF		_LVOApplyAlphaChannelA
	LIBDEF		_LVOMixRGBArrayA
	LIBDEF		_LVOAllocRenderVecClear
	LIBDEF		_LVOCreateAlphaArrayA
	LIBDEF		_LVOMixAlphaChannelA
	LIBDEF		_LVOTintRGBArrayA
	LIBDEF		_LVOGetPaletteAttrs		; strictly private
	LIBDEF		_LVORemapArrayA			; strictly private

;==========================================================================

	ENDC
