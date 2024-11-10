package com.example.myapplication.ui.components

import androidx.compose.foundation.Image
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.myapplication.R
import com.example.myapplication.domain.Star

@Composable
fun StarItem(star: Star, onClick: () -> Unit) {
    Column(modifier = Modifier
        .padding(10.dp)
        .clickable(onClick = onClick)
    ) {
        Text(text = "Name: ${star.name}", fontSize = 18.sp)
        Text(text = "Galaxy: ${star.galaxy}")
        Text(text = "Constellation: ${star.constellation}")
    }
}

@Composable
fun StarItemDetails(star: Star) {
    Column(modifier = Modifier.padding(10.dp)) {
        Text(text = "Name: ${star.name}", fontSize = 18.sp)
        Text(text = "Radius: ${star.radius}")
        Text(text = "Position on x-axis: ${star.xPosition}")
        Text(text = "Position on y-axis: ${star.yPosition}")
        Text(text = "Galaxy: ${star.galaxy}")
        Text(text = "Constellation: ${star.constellation}")
        Text(text = "Temperature: ${star.temperature}")
        Text(text = "Description: ${star.description}")

        Image (
            painter = painterResource(id = R.drawable.star),
            contentDescription = "Star Image",
            modifier = Modifier.size(100.dp)
        )
    }
}