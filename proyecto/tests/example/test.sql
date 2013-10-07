-- phpMyAdmin SQL Dump
-- version 4.0.6deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Oct 07, 2013 at 02:08 AM
-- Server version: 5.5.31-1
-- PHP Version: 5.5.3-1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `test`
--

-- --------------------------------------------------------

--
-- Table structure for table `gauss`
--

CREATE TABLE IF NOT EXISTS `gauss` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `datos` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=12 ;

--
-- Dumping data for table `gauss`
--

INSERT INTO `gauss` (`id`, `datos`) VALUES
(1, 1),
(2, 2),
(3, 2),
(4, 3),
(5, 3),
(6, 3),
(7, 3),
(8, 4),
(9, 4),
(10, 4),
(11, 5);

-- --------------------------------------------------------

--
-- Table structure for table `jitter`
--

CREATE TABLE IF NOT EXISTS `jitter` (
  `data` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `jitter`
--

INSERT INTO `jitter` (`data`) VALUES
(94),
(48),
(96),
(96),
(96),
(48),
(96),
(48),
(1),
(47),
(48),
(16),
(32),
(48),
(48),
(49),
(47),
(96),
(48),
(7),
(41),
(48),
(48),
(48),
(54),
(90),
(48),
(96),
(29),
(67),
(48),
(146),
(92),
(96),
(34),
(62),
(67),
(29),
(48),
(96),
(48),
(96),
(96);

-- --------------------------------------------------------

--
-- Table structure for table `kdetest`
--

CREATE TABLE IF NOT EXISTS `kdetest` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `datos` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=44 ;

--
-- Dumping data for table `kdetest`
--

INSERT INTO `kdetest` (`id`, `datos`) VALUES
(1, 94),
(2, 48),
(3, 96),
(4, 96),
(5, 96),
(6, 48),
(7, 96),
(8, 48),
(9, 1),
(10, 47),
(11, 48),
(12, 16),
(13, 32),
(14, 48),
(15, 48),
(16, 49),
(17, 47),
(18, 96),
(19, 48),
(20, 7),
(21, 41),
(22, 48),
(23, 48),
(24, 48),
(25, 54),
(26, 90),
(27, 48),
(28, 96),
(29, 29),
(30, 67),
(31, 48),
(32, 146),
(33, 92),
(34, 96),
(35, 34),
(36, 62),
(37, 67),
(38, 29),
(39, 48),
(40, 96),
(41, 48),
(42, 96),
(43, 96);

-- --------------------------------------------------------

--
-- Table structure for table `kstest`
--

CREATE TABLE IF NOT EXISTS `kstest` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `datos` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=26 ;

--
-- Dumping data for table `kstest`
--

INSERT INTO `kstest` (`id`, `datos`) VALUES
(1, 1),
(2, 1),
(3, 1),
(4, 1),
(5, 2),
(6, 2),
(7, 2),
(8, 2),
(9, 2),
(10, 2),
(11, 3),
(12, 3),
(13, 3),
(14, 4),
(15, 4),
(16, 4),
(17, 4),
(18, 4),
(19, 5),
(20, 5),
(21, 5),
(22, 5),
(23, 6),
(24, 6),
(25, 6);

-- --------------------------------------------------------

--
-- Table structure for table `pdftest1`
--

CREATE TABLE IF NOT EXISTS `pdftest1` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `datos` float NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=105 ;

--
-- Dumping data for table `pdftest1`
--

INSERT INTO `pdftest1` (`id`, `datos`) VALUES
(1, 7),
(2, 7),
(3, 7),
(4, 7),
(5, 7),
(6, 7),
(7, 7),
(8, 7),
(9, 7),
(10, 7),
(11, 7),
(12, 7),
(13, 7),
(14, 7),
(15, 7),
(16, 7),
(17, 7),
(18, 7),
(19, 7),
(20, 7),
(21, 6.4),
(22, 6.4),
(23, 6.4),
(24, 6.4),
(25, 6.4),
(26, 6.4),
(27, 6.4),
(28, 6.4),
(29, 6.4),
(30, 6.4),
(31, 6.4),
(32, 6.4),
(33, 6.4),
(34, 6.4),
(35, 6.4),
(36, 6.4),
(37, 6.4),
(38, 6.4),
(39, 6.1),
(40, 6.1),
(41, 6.1),
(42, 6.1),
(43, 6.1),
(44, 6.1),
(45, 6.1),
(46, 6.1),
(47, 6.1),
(48, 6.1),
(49, 6.1),
(50, 6.1),
(51, 6.1),
(52, 7.1),
(53, 7.1),
(54, 7.1),
(55, 7.1),
(56, 7.1),
(57, 7.1),
(58, 7.1),
(59, 7.1),
(60, 7.1),
(61, 7.1),
(62, 7.1),
(63, 7.1),
(64, 7.1),
(65, 7.1),
(66, 7.1),
(67, 5.6),
(68, 5.6),
(69, 5.6),
(70, 5.6),
(71, 5.6),
(72, 5.6),
(73, 5.6),
(74, 7.3),
(75, 7.3),
(76, 7.3),
(77, 7.3),
(78, 7.3),
(79, 7.3),
(80, 7.3),
(81, 7.3),
(82, 7.3),
(83, 4.3),
(84, 4.3),
(85, 4.3),
(86, 4.3),
(87, 3),
(88, 3),
(89, 2.5),
(90, 7.9),
(91, 7.9),
(92, 7.9),
(93, 7.9),
(94, 7.9),
(95, 7.9),
(96, 7.9),
(97, 7.9),
(98, 8.5),
(99, 8.5),
(100, 8.5),
(101, 8.5),
(102, 8.7),
(103, 8.7),
(104, 10);

-- --------------------------------------------------------

--
-- Table structure for table `pdftest3`
--

CREATE TABLE IF NOT EXISTS `pdftest3` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `datos` int(11) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=17 ;

--
-- Dumping data for table `pdftest3`
--

INSERT INTO `pdftest3` (`id`, `datos`) VALUES
(1, 2),
(2, 5),
(3, 5),
(4, 10),
(5, 10),
(6, 10),
(7, 15),
(8, 15),
(9, 15),
(10, 15),
(11, 23),
(12, 23),
(13, 23),
(14, 28),
(15, 28),
(16, 33);

-- --------------------------------------------------------

--
-- Table structure for table `scatter`
--

CREATE TABLE IF NOT EXISTS `scatter` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `x` float NOT NULL,
  `y` float NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=110 ;

--
-- Dumping data for table `scatter`
--

INSERT INTO `scatter` (`id`, `x`, `y`) VALUES
(1, 5.97906, 6.8539),
(2, 6.89023, 22.0647),
(3, 8.06109, 10.3407),
(4, 8.89107, 12.709),
(5, 8.97417, 14.5527),
(6, 10.2869, 23.9532),
(7, 11.2404, 32.9056),
(8, 12.854, 20.6448),
(9, 12.35, 36.5918),
(10, 13.9737, 38.2189),
(11, 15.3042, 26.0073),
(12, 16.4116, 28.319),
(13, 17.8441, 30.3572),
(14, 17.5566, 39.5338),
(15, 19.1509, 41.1881),
(16, 20.5373, 43.8698),
(17, 20.2615, 52.4943),
(18, 22.8161, 54.679),
(19, 23.9019, 56.824),
(20, 25.2948, 44.4845),
(21, 26.3513, 46.9908),
(22, 26.2243, 48.5651),
(23, 27.8951, 50.6995),
(24, 27.8952, 66.1492),
(25, 29.3543, 68.8146),
(26, 30.2816, 70.6637),
(27, 31.499, 72.5029),
(28, 32.2828, 67.4267),
(29, 33.5537, 69.4909),
(30, 34.3147, 78.1688),
(31, 35.3411, 66.5038),
(32, 37.0264, 75.7513),
(33, 38.0421, 84.6128),
(34, 38.4147, 79.906),
(35, 40.1236, 81.4239),
(36, 41.2094, 76.7906),
(37, 41.6449, 92.6379),
(38, 43.1185, 87.7521),
(39, 43.0151, 89.0689),
(40, 44.1011, 98.7842),
(41, 45.3596, 93.9116),
(42, 46.7637, 95.6158),
(43, 47.1932, 104.136),
(44, 49.3776, 99.9933),
(45, 49.7819, 108.945),
(46, 49.9127, 96.4263),
(47, 51.499, 112.055),
(48, 52.7393, 114.674),
(49, 54.6182, 102.791),
(50, 54.2427, 118.156),
(51, 55.1911, 120.151),
(52, 56.3103, 108.12),
(53, 56.4722, 124.281),
(54, 59.6771, 112.375),
(55, 59.2542, 128.162),
(56, 59.6509, 130.346),
(57, 61.2426, 118.714),
(58, 61.9549, 134.026),
(59, 63.4294, 129.597),
(60, 64.0123, 131.506),
(61, 65.4896, 133.761),
(62, 66.9558, 135.822),
(63, 67.4764, 130.172),
(64, 67.9429, 139.278),
(65, 69.9207, 134.685),
(66, 71.412, 150.246),
(67, 70.6647, 145.945),
(68, 72.6574, 154.147),
(69, 74.4336, 142.404),
(70, 75.3044, 158.192),
(71, 75.6385, 160.295),
(72, 76.7506, 155.457),
(73, 78.1767, 150.601),
(74, 78.8632, 159.012),
(75, 79.4659, 168.137),
(76, 80.041, 156.859),
(77, 82.619, 172.809),
(78, 82.5318, 174.585),
(79, 83.8829, 176.856),
(80, 84.9092, 178.721),
(81, 84.7813, 173.517),
(82, 85.7318, 182.15),
(83, 86.9597, 184.126),
(84, 87.3447, 179.491),
(85, 89.73, 188.21),
(86, 90.2463, 190.666),
(87, 91.0117, 178.304),
(88, 92.2489, 180.754),
(89, 94.2492, 189.134),
(90, 94.7145, 198.447),
(91, 96.1682, 200.207),
(92, 95.5337, 188.495),
(93, 97.7143, 197.199),
(94, 98.291, 206.047),
(95, 99.2063, 201.656),
(96, 100.106, 203.367),
(97, 101.486, 205.818),
(98, 102.663, 200.249),
(99, 103.949, 209.689),
(100, 105.569, 211.147),
(101, 105.171, 220.445),
(102, 106.38, 208.787),
(103, 106.914, 210.386),
(104, 108.881, 212.773),
(105, 109.126, 228.249),
(106, 110.15, 230.112),
(107, 112.601, 218.143),
(108, 111.663, 227.62),
(109, 114.569, 236.234);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;