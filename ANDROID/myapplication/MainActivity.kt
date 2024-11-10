package com.example.myapplication

import android.icu.text.CaseMap.Title
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.activity.viewModels
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.lazy.items
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.verticalScroll
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.focus.focusModifier
import androidx.compose.ui.layout.ContentScale
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.font.Font
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.navigation.NavController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.rememberNavController
import com.example.myapplication.domain.Star
import com.example.myapplication.modelView.StarModelView
import com.example.myapplication.repository.StarRepository
import com.example.myapplication.ui.components.StarItem
import com.example.myapplication.ui.components.StarItemDetails
import com.example.myapplication.ui.theme.MyApplicationTheme
import com.example.myapplication.userInterface.AddStar
import com.example.myapplication.userInterface.EditStar
import com.example.myapplication.userInterface.SeeAllStars
import com.example.myapplication.userInterface.StarDetails


class MainActivity : ComponentActivity() {
    private val starModelView: StarModelView by viewModels()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            MyApplicationTheme {
                Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                    MainPage(
                        title = stringResource(R.string.app_name),
                        starModelView = starModelView,
                        modifier = Modifier.padding(innerPadding)
                    )
                }
            }
        }
    }
}

@Composable
fun MainPage(title: String, starModelView: StarModelView, modifier: Modifier = Modifier) {
    val navController = rememberNavController()
    NavHost(navController = navController, startDestination = "SeeAllStars") {
        composable("SeeAllStars") {
            SeeAllStars(
                starList = starModelView.stars,
                navController = navController,
                starModelView = starModelView,
                modifier = modifier
            )
        }

        composable("StarDetails/{starId}") { backStackEntry ->
            val starId = backStackEntry.arguments?.getString("starId")?.toInt()

            if (starId != null) {
                StarDetails(starId = starId, navController = navController, starModelView = starModelView)
            }
        }

        composable("AddStarScreen") {
            AddStar(navController = navController, starModelView = starModelView)
        }

        composable("EditStar/{starId}") { backStackEntry ->
            val starId = backStackEntry.arguments?.getString("starId")?.toInt()
            if (starId != null) {
                EditStar(starId = starId, navController = navController, starModelView = starModelView)
            }
        }
    }}






@Preview(showBackground = true)
@Composable
fun MainPagePreview() {
    MyApplicationTheme {
        MainPage(
            title = stringResource(R.string.app_name),
            starModelView = StarModelView(),
        )
    }
}