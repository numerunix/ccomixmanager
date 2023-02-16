-- Valentina Studio --
-- MySQL dump --
-- ---------------------------------------------------------


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
-- ---------------------------------------------------------


-- DROP DATABASE "ComixManager" ----------------------------
DROP DATABASE IF EXISTS `ComixManager`;
-- ---------------------------------------------------------


-- CREATE DATABASE "ComixManager" --------------------------
CREATE DATABASE `ComixManager` CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;
USE `ComixManager`;
-- ---------------------------------------------------------


-- CREATE TABLE "Negozi" ---------------------------------------
CREATE TABLE `Negozi`( 
	`idNegozio` BigInt( 255 ) UNSIGNED AUTO_INCREMENT NOT NULL,
	`Nome` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Indirizzo` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Citta` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Telefono` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	PRIMARY KEY ( `idNegozio` ),
	CONSTRAINT `unique nome_indirizzo_citta` UNIQUE( `Nome`, `Citta`, `Indirizzo` ),
	CONSTRAINT `unique_Telefono` UNIQUE( `Telefono` ) )
CHARACTER SET = utf8mb4
COLLATE = utf8mb4_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 2;-- -------------------------------------------------------------;


-- CREATE TABLE "Categorie" ------------------------------------
CREATE TABLE `Categorie`( 
	`IDCategoria` BigInt( 255 ) UNSIGNED AUTO_INCREMENT NOT NULL,
	`Nome` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Note` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	PRIMARY KEY ( `IDCategoria` ),
	CONSTRAINT `unique_IDCategoria` UNIQUE( `IDCategoria` ),
	CONSTRAINT `unique_nome` UNIQUE( `Nome` ) )
CHARACTER SET = utf8mb4
COLLATE = utf8mb4_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 4;-- -------------------------------------------------------------;


-- CREATE TABLE "Fornitori" ------------------------------------
CREATE TABLE `Fornitori`( 
	`idFornitore` BigInt( 255 ) UNSIGNED AUTO_INCREMENT NOT NULL,
	`Nome` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Indirizzo` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Citta` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Provincia` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Telefono` VarChar( 45 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Fax` VarChar( 45 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`eMail` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`SitoWeb` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Note` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	PRIMARY KEY ( `idFornitore` ),
	CONSTRAINT `unique_fax` UNIQUE( `Fax` ),
	CONSTRAINT `unique_idFornitore` UNIQUE( `idFornitore` ) )
CHARACTER SET = utf8mb4
COLLATE = utf8mb4_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 6;-- -------------------------------------------------------------;


-- CREATE TABLE "Dipendenti" -----------------------------------
CREATE TABLE `Dipendenti`( 
	`idDipendente` BigInt( 255 ) UNSIGNED AUTO_INCREMENT NOT NULL,
	`Nome` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Cognome` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Cellulare` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`idNegozio` BigInt( 255 ) UNSIGNED NOT NULL,
	PRIMARY KEY ( `idDipendente` ),
	CONSTRAINT `unique nome_cognome_cellulare` UNIQUE( `Cellulare`, `Cognome`, `Nome` ),
	CONSTRAINT `unique_cellulare` UNIQUE( `Cellulare` ),
	CONSTRAINT `unique_idDipendente` UNIQUE( `idDipendente` ) )
CHARACTER SET = utf8mb4
COLLATE = utf8mb4_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 2;-- -------------------------------------------------------------;


-- CREATE TABLE "Editori" --------------------------------------
CREATE TABLE `Editori`( 
	`IdEditore` BigInt( 255 ) UNSIGNED AUTO_INCREMENT NOT NULL,
	`Nome` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Sconto` TinyInt( 255 ) NOT NULL,
	`Note` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	PRIMARY KEY ( `IdEditore` ),
	CONSTRAINT `unique_IdEditore` UNIQUE( `IdEditore` ),
	CONSTRAINT `unique_nome_sconto_note` UNIQUE( `Nome`, `Note`, `Sconto` ) )
CHARACTER SET = utf8mb4
COLLATE = utf8mb4_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 2;-- -------------------------------------------------------------;


-- CREATE TABLE "Clienti" --------------------------------------
CREATE TABLE `Clienti`( 
	`IdCliente` BigInt( 255 ) UNSIGNED AUTO_INCREMENT NOT NULL,
	`Nome` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Cognome` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`DataNascita` Date NOT NULL,
	`Indirizzo` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Cap` VarChar( 5 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Citta` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Provincia` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Telefono` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Fax` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`eMail` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`SitoWeb` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Note` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Sconto` Int( 255 ) UNSIGNED NOT NULL,
	PRIMARY KEY ( `IdCliente` ),
	CONSTRAINT `unique_email` UNIQUE( `eMail` ),
	CONSTRAINT `unique_fax` UNIQUE( `Fax` ),
	CONSTRAINT `unique_IdCliente` UNIQUE( `IdCliente` ),
	CONSTRAINT `unique_sitoweb` UNIQUE( `SitoWeb` ),
	CONSTRAINT `unique_telefono` UNIQUE( `Telefono` ) )
CHARACTER SET = utf8mb4
COLLATE = utf8mb4_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 2;-- -------------------------------------------------------------;


-- CREATE TABLE "Collane" --------------------------------------
CREATE TABLE `Collane`( 
	`IdCollana` BigInt( 255 ) UNSIGNED AUTO_INCREMENT NOT NULL,
	`Nome` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Note` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`idEditore` BigInt( 255 ) UNSIGNED NOT NULL,
	PRIMARY KEY ( `IdCollana` ),
	CONSTRAINT `unique_IdCollana` UNIQUE( `IdCollana` ) )
CHARACTER SET = utf8mb4
COLLATE = utf8mb4_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 4;-- -------------------------------------------------------------;


-- CREATE TABLE "Oggetti" --------------------------------------
CREATE TABLE `Oggetti`( 
	`idOggetto` BigInt( 255 ) UNSIGNED AUTO_INCREMENT NOT NULL,
	`Quantita` Int( 255 ) NOT NULL,
	`Prezzo` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Sconto` Int( 255 ) NOT NULL,
	`Vendita` Int( 255 ) NOT NULL,
	`Minimo` Int( 255 ) NOT NULL,
	`idDipendente` BigInt( 255 ) UNSIGNED NOT NULL,
	`idNegozio` BigInt( 255 ) UNSIGNED NOT NULL,
	`idArticolo` BigInt( 255 ) UNSIGNED NOT NULL,
	PRIMARY KEY ( `idOggetto` ),
	CONSTRAINT `unique_articoli_dipendenti_negozi_oggetti` UNIQUE( `idArticolo`, `idOggetto`, `idDipendente`, `idNegozio` ),
	CONSTRAINT `unique_idOggetto` UNIQUE( `idOggetto` ) )
CHARACTER SET = utf8mb4
COLLATE = utf8mb4_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 4;-- -------------------------------------------------------------;


-- CREATE TABLE "Articoli" -------------------------------------
CREATE TABLE `Articoli`( 
	`idArticolo` BigInt( 255 ) UNSIGNED AUTO_INCREMENT NOT NULL,
	`Descrizione` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`CodiceABarre` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`Iva` Int( 255 ) UNSIGNED NOT NULL,
	`Note` VarChar( 255 ) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
	`idCollana` BigInt( 255 ) UNSIGNED NOT NULL,
	`idCategoria` BigInt( 255 ) UNSIGNED NOT NULL,
	`idEditore` BigInt( 255 ) UNSIGNED NOT NULL,
	`idFornitore` BigInt( 255 ) UNSIGNED NOT NULL,
	`Numero` BigInt( 255 ) UNSIGNED NOT NULL,
	`DataPubblicazione` Date NOT NULL,
	`idNegozio` BigInt( 255 ) UNSIGNED NOT NULL,
	PRIMARY KEY ( `idArticolo` ),
	CONSTRAINT `unique_codiceABarre` UNIQUE( `CodiceABarre` ),
	CONSTRAINT `unique_idArticolo` UNIQUE( `idArticolo` ) )
CHARACTER SET = utf8mb4
COLLATE = utf8mb4_general_ci
ENGINE = InnoDB
AUTO_INCREMENT = 2;-- -------------------------------------------------------------;


-- CREATE INDEX "unique_telefono" ------------------------------
CREATE INDEX `unique_telefono` USING BTREE ON `Fornitori`( `Telefono` );-- -------------------------------------------------------------;


-- CREATE INDEX "lnk_Negozi_Dipendenti" ------------------------
CREATE INDEX `lnk_Negozi_Dipendenti` USING BTREE ON `Dipendenti`( `idNegozio` );-- -------------------------------------------------------------;


-- CREATE INDEX "unique_nome_idEditore" ------------------------
CREATE INDEX `unique_nome_idEditore` USING BTREE ON `Collane`( `idEditore`, `Nome` );-- -------------------------------------------------------------;


-- CREATE INDEX "lnk_Articoli_Oggetti" -------------------------
CREATE INDEX `lnk_Articoli_Oggetti` USING BTREE ON `Oggetti`( `idArticolo` );-- -------------------------------------------------------------;


-- CREATE INDEX "lnk_Dipendenti_Oggetti" -----------------------
CREATE INDEX `lnk_Dipendenti_Oggetti` USING BTREE ON `Oggetti`( `idDipendente` );-- -------------------------------------------------------------;


-- CREATE INDEX "lnk_Negozi_Oggetti" ---------------------------
CREATE INDEX `lnk_Negozi_Oggetti` USING BTREE ON `Oggetti`( `idNegozio` );-- -------------------------------------------------------------;


-- CREATE INDEX "lnk_Categorie_Articoli" -----------------------
CREATE INDEX `lnk_Categorie_Articoli` USING BTREE ON `Articoli`( `idCategoria` );-- -------------------------------------------------------------;


-- CREATE INDEX "lnk_Collane_Articoli" -------------------------
CREATE INDEX `lnk_Collane_Articoli` USING BTREE ON `Articoli`( `idCollana` );-- -------------------------------------------------------------;


-- CREATE INDEX "lnk_Editori_Articoli" -------------------------
CREATE INDEX `lnk_Editori_Articoli` USING BTREE ON `Articoli`( `idEditore` );-- -------------------------------------------------------------;


-- CREATE INDEX "lnk_Fornitori_Articoli" -----------------------
CREATE INDEX `lnk_Fornitori_Articoli` USING BTREE ON `Articoli`( `idFornitore` );-- -------------------------------------------------------------;


-- CREATE LINK "lnk_Negozi_Dipendenti" -------------------------
ALTER TABLE `Dipendenti`
	ADD CONSTRAINT `lnk_Negozi_Dipendenti` FOREIGN KEY ( `idNegozio` )
	REFERENCES `Negozi`( `idNegozio` )
	ON DELETE Cascade
	ON UPDATE Cascade;-- -------------------------------------------------------------;


-- CREATE LINK "lnk_Editori_Collane" ---------------------------
ALTER TABLE `Collane`
	ADD CONSTRAINT `lnk_Editori_Collane` FOREIGN KEY ( `idEditore` )
	REFERENCES `Editori`( `IdEditore` )
	ON DELETE Cascade
	ON UPDATE Cascade;-- -------------------------------------------------------------;


-- CREATE LINK "lnk_Articoli_Oggetti" --------------------------
ALTER TABLE `Oggetti`
	ADD CONSTRAINT `lnk_Articoli_Oggetti` FOREIGN KEY ( `idArticolo` )
	REFERENCES `Articoli`( `idArticolo` )
	ON DELETE Cascade
	ON UPDATE Cascade;-- -------------------------------------------------------------;


-- CREATE LINK "lnk_Dipendenti_Oggetti" ------------------------
ALTER TABLE `Oggetti`
	ADD CONSTRAINT `lnk_Dipendenti_Oggetti` FOREIGN KEY ( `idDipendente` )
	REFERENCES `Dipendenti`( `idDipendente` )
	ON DELETE Cascade
	ON UPDATE Cascade;-- -------------------------------------------------------------;


-- CREATE LINK "lnk_Negozi_Oggetti" ----------------------------
ALTER TABLE `Oggetti`
	ADD CONSTRAINT `lnk_Negozi_Oggetti` FOREIGN KEY ( `idNegozio` )
	REFERENCES `Negozi`( `idNegozio` )
	ON DELETE Cascade
	ON UPDATE Cascade;-- -------------------------------------------------------------;


-- CREATE LINK "lnk_Categorie_Articoli" ------------------------
ALTER TABLE `Articoli`
	ADD CONSTRAINT `lnk_Categorie_Articoli` FOREIGN KEY ( `idCategoria` )
	REFERENCES `Categorie`( `IDCategoria` )
	ON DELETE Cascade
	ON UPDATE Cascade;-- -------------------------------------------------------------;


-- CREATE LINK "lnk_Collane_Articoli" --------------------------
ALTER TABLE `Articoli`
	ADD CONSTRAINT `lnk_Collane_Articoli` FOREIGN KEY ( `idCollana` )
	REFERENCES `Collane`( `IdCollana` )
	ON DELETE Cascade
	ON UPDATE Cascade;-- -------------------------------------------------------------;


-- CREATE LINK "lnk_Editori_Articoli" --------------------------
ALTER TABLE `Articoli`
	ADD CONSTRAINT `lnk_Editori_Articoli` FOREIGN KEY ( `idEditore` )
	REFERENCES `Editori`( `IdEditore` )
	ON DELETE Cascade
	ON UPDATE Cascade;-- -------------------------------------------------------------;


-- CREATE LINK "lnk_Fornitori_Articoli" ------------------------
ALTER TABLE `Articoli`
	ADD CONSTRAINT `lnk_Fornitori_Articoli` FOREIGN KEY ( `idFornitore` )
	REFERENCES `Fornitori`( `idFornitore` )
	ON DELETE Cascade
	ON UPDATE Cascade;-- -------------------------------------------------------------;


/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
-- ---------------------------------------------------------


