package com.lijing.media.player

object LeeNativePlayer {

    init {
        System.loadLibrary("lee_media")
    }

    external fun stringFromJNI(): String
    external fun createPlayer(): Long
    external fun start(player: Long)
    external fun getName(player: Long): String
    external fun pause(player: Long)
    external fun release(player: Long)
}