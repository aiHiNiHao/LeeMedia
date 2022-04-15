package com.lijing.media

import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.lijing.media.databinding.ActivityMainBinding
import com.lijing.media.player.LeeNativePlayer

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.jniTest.setOnClickListener {
            startActivity(Intent(this@MainActivity, JniTestActivity::class.java))
        }
        binding.mediaCodecTest.setOnClickListener {
            startActivity(Intent(this@MainActivity, JniTestActivity::class.java))
        }
        binding.pause.setOnClickListener {

        }
        binding.delete.setOnClickListener {

        }
    }


}