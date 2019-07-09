/*
 * TujaSDR ASoC Driver
 *
 * - I2S interface, 64 BCLs per frame, 32 bits per channel, 24 bit data
 *
 * Copyright (c) 2018 TujaSDR
 *
 * Licensed under GPL v2.
 *
 * https://www.kernel.org/doc/html/v4.14/sound/soc/codec.html
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/initval.h>
#include <sound/tlv.h>

#define TUJASDR_FORMATS ( SNDRV_PCM_FMTBIT_S32 )

static struct snd_soc_dai_driver tujasdr_dai = {
	.name = "tujasdr-hifi",
	.playback = {
		.stream_name = "Playback",
		.channels_min = 2,
        .channels_max = 2,
        .rates = SNDRV_PCM_RATE_8000_96000,
		.formats = TUJASDR_FORMATS,
	},
	.capture = {
		.stream_name = "Capture",
		.channels_min = 2,
		.channels_max = 2,
        //.rates = SNDRV_PCM_RATE_96000 ,
        .rates = SNDRV_PCM_RATE_8000_96000,
		.formats = TUJASDR_FORMATS,
	}
};

static struct snd_soc_codec_driver tujasdr_codec_driver = {
};

static int tujasdr_probe(struct platform_device *pdev)
{
	return snd_soc_register_codec(&pdev->dev, &tujasdr_codec_driver,
			&tujasdr_dai, 1);
}

static int tujasdr_remove(struct platform_device *pdev)
{
	snd_soc_unregister_codec(&pdev->dev);
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id tujasdr_ids[] = {
	{ .compatible = "tuja,tujasdr", },
	{ }
};
MODULE_DEVICE_TABLE(of, tujasdr_ids);
#endif

static struct platform_driver tujasdr_driver = {
	.driver = {
		.name = "tujasdr",
		.of_match_table = of_match_ptr(tujasdr_ids),
	},
	.probe = tujasdr_probe,
	.remove = tujasdr_remove,
};

module_platform_driver(tujasdr_driver);

MODULE_DESCRIPTION("ASoC TujaSDR driver");
MODULE_AUTHOR("Albin Stigo <albin.stigo@gmail.com>");
MODULE_LICENSE("GPL v2");
