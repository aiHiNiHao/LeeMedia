package com.lijing.media

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.lijing.media.databinding.ActivityMainBinding
import com.lijing.media.databinding.ActivityMediaCodecTestBinding
import com.lijing.media.player.LeeNativePlayer

class MediaCodecTestActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMediaCodecTestBinding
    private var player: Long = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMediaCodecTestBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = LeeNativePlayer.stringFromJNI()
        binding.create.setOnClickListener {
            player = LeeNativePlayer.createPlayer()
            binding.sampleText.text = LeeNativePlayer.getName(player)
        }
        binding.start.setOnClickListener { LeeNativePlayer.start(player) }
        binding.pause.setOnClickListener { LeeNativePlayer.pause(player) }
        binding.delete.setOnClickListener {
            LeeNativePlayer.release(player)
            player = 0
        }
    }


    override fun onDestroy() {
        super.onDestroy()
        if (player != 0L){
            LeeNativePlayer.release(player)
            player = 0
        }
    }
}