const sql = require('mssql');

const getAllReviewsFromRepo = async () =>{
    try {
        const request = new sql.Request();
        const result = await request.query("SELECT r.id AS id, p.title AS product_name, r.customer_name, r.description, r.stars\n" +
            "            FROM Reviews r\n" +
            "            INNER JOIN Product p ON r.product_id = p.id;");
        return result.recordset;
    } catch (error) {
        console.error('Error retrieving reviews:', error);
        throw error;
    }
}

const editReviewFromRepo = async (review) => {
    try{
        const request = new sql.Request();
        const result = await request.query(
            `UPDATE Reviews SET description = '${review.description}', stars = ${review.stars} WHERE id = ${review.id}`
        );
    }catch (error){
        console.error('Error retrieving review by id:', error);
        throw error;
    }
}

const deleteReviewFromRepo = async (review) => {
    try{
        const request = new sql.Request();
        await request.query(`DELETE FROM Reviews WHERE id = ${review.id}`);
    }catch (error){
        console.error('Error deleting review:', error);
        throw error;
    }
}

const addReviewFromRepo = async (review) => {
    try {
        const request = new sql.Request();
        await request.query(`
            INSERT INTO Reviews (id, product_id, customer_name, description, stars) 
            VALUES ('${review.id}', '${review.product_id}', '${review.customer_name}', '${review.description}', '${review.stars}')
        `);
    } catch (error) {
        console.error('Error adding review:', error);
        throw error;
    }
}


module.exports = {
    getAllReviewsFromRepo,
    editReviewFromRepo,
    deleteReviewFromRepo,
    addReviewFromRepo

}