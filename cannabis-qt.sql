PRAGMA foreign_keys=OFF;
BEGIN TRANSACTION;
CREATE TABLE "Clients" ( "Codi" INTEGER PRIMARY KEY AUTOINCREMENT, "DNI" TEXT NOT NULL, "Nom" TEXT, "Cognom1" TEXT, );
COMMIT;
