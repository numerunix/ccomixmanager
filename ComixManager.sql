-- MariaDB dump 10.19  Distrib 10.5.15-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: ComixManager
-- ------------------------------------------------------
-- Server version	10.5.15-MariaDB-0+deb11u1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Articoli`
--

DROP TABLE IF EXISTS `Articoli`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Articoli` (
  `idArticolo` bigint(11) NOT NULL AUTO_INCREMENT,
  `Descrizione` mediumtext COLLATE utf8_bin DEFAULT NULL,
  `codiceABarre` varchar(45) COLLATE utf8_bin NOT NULL,
  `Iva` int(11) NOT NULL DEFAULT 22,
  `Note` mediumtext COLLATE utf8_bin DEFAULT NULL,
  `idCollana` int(11) DEFAULT NULL,
  `idCategoria` int(11) DEFAULT NULL,
  `idEditore` int(11) DEFAULT NULL,
  `idFornitore` int(11) DEFAULT NULL,
  `Numero` int(11) DEFAULT NULL,
  `DataPubblicazione` date NOT NULL,
  PRIMARY KEY (`idArticolo`),
  KEY `fk_Articoli_1_idx` (`idCollana`),
  KEY `fk_Articoli_2_idx` (`idCategoria`),
  KEY `fk_Articoli_3_idx` (`idEditore`),
  KEY `fk_Articoli_4_idx` (`idFornitore`),
  CONSTRAINT `fk_Articoli_1` FOREIGN KEY (`idCollana`) REFERENCES `Collana` (`idCollana`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_Articoli_2` FOREIGN KEY (`idCategoria`) REFERENCES `Categoria` (`idCategoria`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_Articoli_3` FOREIGN KEY (`idEditore`) REFERENCES `Editori` (`idEditore`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_Articoli_4` FOREIGN KEY (`idFornitore`) REFERENCES `Fornitori` (`idFornitore`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Articoli`
--

LOCK TABLES `Articoli` WRITE;
/*!40000 ALTER TABLE `Articoli` DISABLE KEYS */;
INSERT INTO `Articoli` VALUES (1,'1','1',1,'',1,1,1,1,1,'2020-02-02');
/*!40000 ALTER TABLE `Articoli` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Categoria`
--

DROP TABLE IF EXISTS `Categoria`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Categoria` (
  `idCategoria` int(11) NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) COLLATE utf8_bin NOT NULL,
  `Note` varchar(45) COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`idCategoria`),
  UNIQUE KEY `Nome_UNIQUE` (`Nome`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Categoria`
--

LOCK TABLES `Categoria` WRITE;
/*!40000 ALTER TABLE `Categoria` DISABLE KEYS */;
INSERT INTO `Categoria` VALUES (1,'prova','');
/*!40000 ALTER TABLE `Categoria` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Clienti`
--

DROP TABLE IF EXISTS `Clienti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Clienti` (
  `idCliente` bigint(11) NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) COLLATE utf8_bin NOT NULL,
  `Cognome` varchar(45) COLLATE utf8_bin NOT NULL,
  `Indirizzo` tinytext COLLATE utf8_bin DEFAULT NULL,
  `DataNascita` date NOT NULL,
  `Cap` varchar(5) CHARACTER SET utf8 NOT NULL,
  `Citta` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Provincia` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Telefono` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Fax` varchar(45) CHARACTER SET utf8 NOT NULL,
  `EMail` varchar(45) CHARACTER SET utf8 NOT NULL,
  `SitoWeb` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Note` varchar(45) COLLATE utf8_bin DEFAULT NULL,
  `Sconto` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`idCliente`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Clienti`
--

LOCK TABLES `Clienti` WRITE;
/*!40000 ALTER TABLE `Clienti` DISABLE KEYS */;
INSERT INTO `Clienti` VALUES (1,'Giulio','Sorrentino','Via del tutto eccezionale','1984-09-12','80100','napoli','na','00000','','','','',0),(2,'Giulio','Sorrentino','via del tutto eccezionale','1984-09-12','80100','Napoli','NA','00000','','','','',0);
/*!40000 ALTER TABLE `Clienti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Collana`
--

DROP TABLE IF EXISTS `Collana`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Collana` (
  `idCollana` int(11) NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) COLLATE utf8_bin NOT NULL,
  `Note` varchar(45) CHARACTER SET utf8 DEFAULT '0',
  `idEditore` int(11) DEFAULT NULL,
  PRIMARY KEY (`idCollana`),
  KEY `fk_Collana_1_idx` (`idEditore`),
  CONSTRAINT `fk_Collana_1` FOREIGN KEY (`idEditore`) REFERENCES `Editori` (`idEditore`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Collana`
--

LOCK TABLES `Collana` WRITE;
/*!40000 ALTER TABLE `Collana` DISABLE KEYS */;
INSERT INTO `Collana` VALUES (1,'prova','',1);
/*!40000 ALTER TABLE `Collana` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Dipendenti`
--

DROP TABLE IF EXISTS `Dipendenti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Dipendenti` (
  `idDipendente` int(11) NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) COLLATE utf8_bin DEFAULT NULL,
  `Cognome` varchar(45) COLLATE utf8_bin DEFAULT NULL,
  `Cellulare` varchar(45) COLLATE utf8_bin DEFAULT NULL,
  `idNegozio` int(11) DEFAULT NULL,
  PRIMARY KEY (`idDipendente`),
  KEY `fk_Dipendenti_1_idx` (`idNegozio`),
  CONSTRAINT `fk_Dipendenti_1` FOREIGN KEY (`idNegozio`) REFERENCES `Negozi` (`idNegozio`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Dipendenti`
--

LOCK TABLES `Dipendenti` WRITE;
/*!40000 ALTER TABLE `Dipendenti` DISABLE KEYS */;
INSERT INTO `Dipendenti` VALUES (1,'Giulio','Sorrentino','0000',1);
/*!40000 ALTER TABLE `Dipendenti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Editori`
--

DROP TABLE IF EXISTS `Editori`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Editori` (
  `idEditore` int(11) NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `Sconto` int(11) NOT NULL DEFAULT 0,
  `Note` varchar(45) CHARACTER SET utf8 COLLATE utf8_bin DEFAULT NULL,
  PRIMARY KEY (`idEditore`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Editori`
--

LOCK TABLES `Editori` WRITE;
/*!40000 ALTER TABLE `Editori` DISABLE KEYS */;
INSERT INTO `Editori` VALUES (1,'numeronesoft',0,'');
/*!40000 ALTER TABLE `Editori` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Fornitori`
--

DROP TABLE IF EXISTS `Fornitori`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Fornitori` (
  `idFornitore` int(11) NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Indirizzo` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Citta` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Provincia` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Telefono` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Fax` varchar(45) COLLATE utf8_bin DEFAULT NULL,
  `eMail` varchar(45) COLLATE utf8_bin DEFAULT NULL,
  `SitoWeb` varchar(45) COLLATE utf8_bin DEFAULT NULL,
  `Note` varchar(45) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`idFornitore`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Fornitori`
--

LOCK TABLES `Fornitori` WRITE;
/*!40000 ALTER TABLE `Fornitori` DISABLE KEYS */;
INSERT INTO `Fornitori` VALUES (1,'numeronesoft','via del tutto eccezionale','napoli','na','','','00000','','gsorre84@gmail.com');
/*!40000 ALTER TABLE `Fornitori` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Negozi`
--

DROP TABLE IF EXISTS `Negozi`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Negozi` (
  `idNegozio` int(11) NOT NULL AUTO_INCREMENT,
  `Nome` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Indirizzo` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Citta` varchar(45) CHARACTER SET utf8 NOT NULL,
  `Telefono` varchar(45) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`idNegozio`),
  UNIQUE KEY `Telefono_UNIQUE` (`Telefono`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Negozi`
--

LOCK TABLES `Negozi` WRITE;
/*!40000 ALTER TABLE `Negozi` DISABLE KEYS */;
INSERT INTO `Negozi` VALUES (1,'numeronesoft','via del tutto eccezionale','Napoli','000');
/*!40000 ALTER TABLE `Negozi` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Oggetti`
--

DROP TABLE IF EXISTS `Oggetti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `Oggetti` (
  `idOggetto` bigint(11) NOT NULL AUTO_INCREMENT,
  `Quantita` int(11) NOT NULL,
  `Prezzo` varchar(45) COLLATE utf8_bin NOT NULL,
  `Sconto` int(11) DEFAULT NULL,
  `idDipendente` int(11) DEFAULT NULL,
  `idNegozio` int(11) NOT NULL,
  `vendita` int(11) NOT NULL,
  `idArticolo` bigint(11) DEFAULT NULL,
  `Minimo` int(11) unsigned NOT NULL,
  PRIMARY KEY (`idOggetto`),
  KEY `fk_Oggetti_3_idx` (`idDipendente`),
  KEY `fk_Oggetti_2_idx` (`idNegozio`),
  KEY `fk_Oggetti_1_idx` (`idArticolo`),
  CONSTRAINT `fk_Oggetti_1` FOREIGN KEY (`idArticolo`) REFERENCES `Articoli` (`idArticolo`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_Oggetti_2` FOREIGN KEY (`idNegozio`) REFERENCES `Negozi` (`idNegozio`) ON DELETE NO ACTION ON UPDATE NO ACTION,
  CONSTRAINT `fk_Oggetti_3` FOREIGN KEY (`idDipendente`) REFERENCES `Dipendenti` (`idDipendente`) ON DELETE NO ACTION ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Oggetti`
--

LOCK TABLES `Oggetti` WRITE;
/*!40000 ALTER TABLE `Oggetti` DISABLE KEYS */;
INSERT INTO `Oggetti` VALUES (1,1,'1',1,1,1,1,1,1);
/*!40000 ALTER TABLE `Oggetti` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-10-04  6:30:52
