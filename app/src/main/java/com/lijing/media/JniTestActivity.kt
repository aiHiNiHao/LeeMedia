package com.lijing.media

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.lijing.media.databinding.ActivityJniTestBinding
import com.lijing.media.databinding.ActivityMainBinding
import com.lijing.media.player.LeeNativePlayer

class JniTestActivity : AppCompatActivity() {

    private lateinit var binding: ActivityJniTestBinding
    private var player: Long = 0

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityJniTestBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = LeeNativePlayer.stringFromJNI()
        binding.create.setOnClickListener {
            player = LeeNativePlayer.createPlayer()
            binding.sampleText.text = LeeNativePlayer.getName(player)
        }
        binding.start.setOnClickListener { LeeNativePlayer.start(player) }
        binding.pause.setOnClickListener { LeeNativePlayer.pause(player) }
        binding.delete.setOnClickListener { LeeNativePlayer.release(player) }
    }


}