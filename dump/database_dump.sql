-- MySQL dump 10.13  Distrib 8.0.31, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: banksimul
-- ------------------------------------------------------
-- Server version	8.0.30

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `id_account` int unsigned NOT NULL AUTO_INCREMENT,
  `account_type` varchar(10) NOT NULL,
  `balance` double NOT NULL,
  `credit_limit` double NOT NULL,
  `account_owner` varchar(45) NOT NULL,
  PRIMARY KEY (`id_account`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES (1,'credit',4958,600,'Aino Virtanen'),(2,'debit',4000,0,'Juhani Virtanen'),(3,'credit',5000,5000,'Maija Virta'),(4,'debit',4000,0,'Eino Koski');
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `card`
--

DROP TABLE IF EXISTS `card`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `card` (
  `id_card` int unsigned NOT NULL AUTO_INCREMENT,
  `card_number` varchar(45) NOT NULL,
  `pin` varchar(255) NOT NULL,
  `id_user` int unsigned NOT NULL,
  PRIMARY KEY (`id_card`),
  UNIQUE KEY `card_number_UNIQUE` (`card_number`),
  KEY `id_user_idx` (`id_user`),
  CONSTRAINT `card_user` FOREIGN KEY (`id_user`) REFERENCES `user` (`id_user`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `card`
--

LOCK TABLES `card` WRITE;
/*!40000 ALTER TABLE `card` DISABLE KEYS */;
INSERT INTO `card` VALUES (1,'123456','$2a$10$6xBNVX01jrzWvbZcKe5ysOO7.Kr2zv4QCI6GInuAeSoSdC77I0.j6',1),(2,'654321','$2a$10$rHGz3BoTX8llZFFhXKFcQe5iv/66Km0uE7hBb2nN69Zz/dYIeRzsS',2),(3,'112233','$2a$10$2S57S89UowUXuxn/GBVP0uwqlXJHjxyq0N4ozjXZKL0DUIfbiSQKW',3),(4,'332211','$2a$10$Q8CN9RCKJUPMruHys1Qk0.TQs.lHecXwa0bkLj5mOcsfaGHyMB2Ti',4);
/*!40000 ALTER TABLE `card` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `transaction`
--

DROP TABLE IF EXISTS `transaction`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `transaction` (
  `id_transaction` int unsigned NOT NULL AUTO_INCREMENT,
  `transaction_date` timestamp NOT NULL,
  `activity` varchar(45) NOT NULL,
  `amount` double NOT NULL,
  `id_account` int unsigned NOT NULL,
  PRIMARY KEY (`id_transaction`),
  KEY `id_account_idx` (`id_account`),
  CONSTRAINT `transaction_account` FOREIGN KEY (`id_account`) REFERENCES `account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=51 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `transaction`
--

LOCK TABLES `transaction` WRITE;
/*!40000 ALTER TABLE `transaction` DISABLE KEYS */;
INSERT INTO `transaction` VALUES (1,'2022-12-04 22:00:00','nosto',10,1),(2,'2022-12-04 22:00:00','nosto',10,1),(3,'2022-12-04 22:00:00','nosto',20,1),(4,'2022-12-04 22:00:00','nosto',20,1),(5,'2022-12-04 22:00:00','nosto',20,1),(6,'2022-12-04 22:00:00','nosto',2.9350482956806208e-300,1),(7,'2022-12-04 22:00:00','nosto',20,1),(8,'2022-12-04 22:00:00','nosto',5.8700965913612416e-300,1),(10,'2022-12-04 22:00:00','nosto',20,1),(11,'2022-12-04 22:00:00','nosto',500,1),(12,'2022-12-04 22:00:00','nosto',500,1),(13,'2022-12-04 22:00:00','nosto',500,1),(14,'2022-12-04 22:00:00','nosto',500,1),(15,'2022-12-04 22:00:00','nosto',500,1),(16,'2022-12-04 22:00:00','nosto',500,1),(17,'2022-12-04 22:00:00','nosto',500,1),(18,'2022-12-04 22:00:00','nosto',500,1),(19,'2022-12-04 22:00:00','nosto',500,1),(20,'2022-12-04 22:00:00','nosto',500,1),(21,'2022-12-04 22:00:00','nosto',500,1),(22,'2022-12-04 22:00:00','nosto',500,1),(23,'2022-12-04 22:00:00','nosto',500,1),(24,'2022-12-04 22:00:00','nosto',500,1),(25,'2022-12-04 22:00:00','nosto',500,1),(26,'2022-12-04 22:00:00','nosto',50,1),(27,'2022-12-04 22:00:00','nosto',0,1),(28,'2022-12-04 22:00:00','nosto',0,1),(29,'2022-12-04 22:00:00','nosto',20,1),(30,'2022-12-04 22:00:00','nosto',20,1),(31,'2022-12-04 22:00:00','nosto',20,1),(32,'2022-12-04 22:00:00','nosto',0,1),(33,'2022-12-04 22:00:00','nosto',1,1),(34,'2022-12-04 22:00:00','nosto',2,1),(35,'2022-12-04 22:00:00','nosto',1,1),(36,'2022-12-04 22:00:00','nosto',5,1),(37,'2022-12-04 22:00:00','nosto',5,1),(38,'2022-12-04 22:00:00','nosto',1,1),(39,'2022-12-05 22:00:00','luottoraja',500,1),(40,'2022-12-05 22:00:00','luottoraja',500,1),(41,'2022-12-05 22:00:00','luottoraja',500,1),(42,'2022-12-05 22:00:00','luottoraja',500,1),(43,'2022-12-05 22:00:00','luottorajan korotus',500,1),(44,'2022-12-05 22:00:00','luottorajan korotus',1000,1),(45,'2022-12-05 22:00:00','luottorajan korotus',500,1),(46,'2022-12-06 22:00:00','nosto',1,1),(47,'2022-12-07 22:00:00','nosto',20,1),(48,'2022-12-07 22:00:00','nosto',2,1),(49,'2022-12-07 22:00:00','luottorajan korotus',500,1),(50,'2022-12-07 22:00:00','nosto',20,1);
/*!40000 ALTER TABLE `transaction` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user` (
  `id_user` int unsigned NOT NULL AUTO_INCREMENT,
  `fname` varchar(45) NOT NULL,
  `lname` varchar(45) NOT NULL,
  `address` varchar(45) NOT NULL,
  `phone` varchar(45) NOT NULL,
  PRIMARY KEY (`id_user`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES (1,'Aino','Virtanen','Pakkahuoneenkatu 7','+35844558812'),(2,'Juhani','Virtanen','Uusikatu 5','+358986655429'),(3,'Maija','Virta','Viestikatu 2','+358004455771'),(4,'Eino','Koski','Vetoporontie 1','+35855778890'),(5,'Liisa','Koski','Vetoporontie 1','+35855346790');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user_account`
--

DROP TABLE IF EXISTS `user_account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `user_account` (
  `id_user` int unsigned NOT NULL,
  `id_account` int unsigned NOT NULL,
  PRIMARY KEY (`id_user`,`id_account`),
  KEY `user_account_account_idx` (`id_account`),
  CONSTRAINT `user_account_account` FOREIGN KEY (`id_account`) REFERENCES `account` (`id_account`) ON DELETE RESTRICT ON UPDATE CASCADE,
  CONSTRAINT `user_accout_user` FOREIGN KEY (`id_user`) REFERENCES `user` (`id_user`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user_account`
--

LOCK TABLES `user_account` WRITE;
/*!40000 ALTER TABLE `user_account` DISABLE KEYS */;
INSERT INTO `user_account` VALUES (1,1),(2,2),(3,3),(4,4);
/*!40000 ALTER TABLE `user_account` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-12-08 16:56:38
