package com.example.android.medical_applications;

import android.content.Intent;
import android.media.Image;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private ImageButton muscle;
    private ImageButton brain;
    private ImageButton heart;
    private ImageButton settings;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        muscle = (ImageButton) findViewById(R.id.muscle);

        muscle.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent muscleIntent = new Intent(MainActivity.this, Muscle.class);
                //Start the new activity
                startActivity(muscleIntent);
            }
        });

        brain = (ImageButton) findViewById(R.id.brain);

        brain.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent brainIntent = new Intent(MainActivity.this, Brain.class);
                //Start the new activity
                startActivity(brainIntent);
            }
        });

        heart = (ImageButton) findViewById(R.id.heart);

        heart.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent heartIntent = new Intent(MainActivity.this, Heart.class);
                //Start the new activity
                startActivity(heartIntent);
            }
        });

        settings = (ImageButton) findViewById(R.id.settings);

        settings.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent settingsIntent = new Intent(MainActivity.this, Settings.class);
                //Start the new activity
                startActivity(settingsIntent);
            }
        });

    }
}