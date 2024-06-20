namespace RecipeManager.Models
{
    public class Recipe
    {
        public int Id { get; set; }
        public string Author { get; set; }
        public string Name { get; set; }
        public string Type { get; set; }
        public string Ingredients { get; set; }
        public string Instructions { get; set; }
    }
}
