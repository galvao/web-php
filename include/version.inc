<?php // vim: et
/* The format is:
 * array(
 *     "major release number" => array(
 *         "release" => array(
 *             "source/windows" => array(
 *                 "filename" => "filename.tar.bz2",
 *                 "name"     => "package name",
 *                 "sha256"   => "shasum -256",
 *                 "date"     => "this files release date",
 *                 "note"     => "this file was updated 29feb due to broken phar files..",
 *             ),
 *             "announcement" => "bool, release announcement exists in releases/?",
 *         ),
 *     ),
 * );
 */
$RELEASES = (function() {
    /* PHP 7.3 Release */
    $PHP_7_3_VERSION         = "7.3.8";
    $PHP_7_3_DATE            = "01 Aug 2019";
    $PHP_7_3_TAGS            = ['security']; // Set to ['security'] for security releases.
    $PHP_7_3_SHA256     = array(
        "tar.bz2"       => "d566c630175d9fa84a98d3c9170ec033069e9e20c8d23dea49ae2a976b6c76f5",
        "tar.gz"        => "31af3eff3337fb70733c9b02a3444c3dae662ecab20aeec7fdc3c42e22071490",
        "tar.xz"        => "f6046b2ae625d8c04310bda0737ac660dc5563a8e04e8a46c1ee24ea414ad5a5",
    );

    /* PHP 7.2 Release */
    $PHP_7_2_VERSION         = "7.2.21";
    $PHP_7_2_DATE            = "01 Aug 2019";
    $PHP_7_2_TAGS            = ['security']; // Set to ['security'] for security releases.
    $PHP_7_2_SHA256     = array(
        "tar.bz2"       => "343183a1be8336670171885c761d57ffcae99cbbcf1db43da7cb5565056b14ef",
        "tar.gz"        => "8327682bee4a8fd2edf5bbfcc393d986b945bec433fc74458d05e766701b313c",
        "tar.xz"        => "de06aff019d8f5079115795bd7d8eedd4cd03daecb62d58abb18f492dd995c95",
    );

    /* PHP 7.1 Release */
    $PHP_7_1_VERSION         = "7.1.31";
    $PHP_7_1_DATE            = "01 Aug 2019";
    $PHP_7_1_TAGS            = ['security'];
    $PHP_7_1_SHA256     = array(
        'tar.bz2'       => '767573c2b732e78cc647602ec61fc948941a941a4071db59b522cf5e076825dd',
        'tar.gz'        => 'ea0558735653b9ce63e9cea41dd8f0d0b90dba6c39d39dd9a6aad5cc58b0bdfc',
        'tar.xz'        => '5cb53b63592ec4361f0ab12c684b10430344821a024881a387ead4299df78fa5',
    );

    return array(
        7 => array(
            $PHP_7_3_VERSION => array(
                "announcement" => true,
                "tags" => $PHP_7_3_TAGS,
                "date" => $PHP_7_3_DATE,
                "source" => array(
                    array(
                        "filename" => "php-$PHP_7_3_VERSION.tar.bz2",
                        "name"     => "PHP $PHP_7_3_VERSION (tar.bz2)",
                        "sha256"   => $PHP_7_3_SHA256["tar.bz2"],
                        "date"     => $PHP_7_3_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_3_VERSION.tar.gz",
                        "name"     => "PHP $PHP_7_3_VERSION (tar.gz)",
                        "sha256"   => $PHP_7_3_SHA256["tar.gz"],
                        "date"     => $PHP_7_3_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_3_VERSION.tar.xz",
                        "name"     => "PHP $PHP_7_3_VERSION (tar.xz)",
                        "sha256"   => $PHP_7_3_SHA256["tar.xz"],
                        "date"     => $PHP_7_3_DATE,
                    ),
                ),
            ),
            $PHP_7_2_VERSION => array(
                "announcement" => true,
                "tags" => $PHP_7_2_TAGS,
                "date" => $PHP_7_2_DATE,
                "source" => array(
                    array(
                        "filename" => "php-$PHP_7_2_VERSION.tar.bz2",
                        "name"     => "PHP $PHP_7_2_VERSION (tar.bz2)",
                        "sha256"   => $PHP_7_2_SHA256["tar.bz2"],
                        "date"     => $PHP_7_2_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_2_VERSION.tar.gz",
                        "name"     => "PHP $PHP_7_2_VERSION (tar.gz)",
                        "sha256"   => $PHP_7_2_SHA256["tar.gz"],
                        "date"     => $PHP_7_2_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_2_VERSION.tar.xz",
                        "name"     => "PHP $PHP_7_2_VERSION (tar.xz)",
                        "sha256"   => $PHP_7_2_SHA256["tar.xz"],
                        "date"     => $PHP_7_2_DATE,
                    ),
                ),
            ),
            $PHP_7_1_VERSION => array(
                "announcement" => true,
                "tags" => $PHP_7_1_TAGS,
                "date" => $PHP_7_1_DATE,
                "source" => array(
                    array(
                        "filename" => "php-$PHP_7_1_VERSION.tar.bz2",
                        "name"     => "PHP $PHP_7_1_VERSION (tar.bz2)",
                        "sha256"   => $PHP_7_1_SHA256["tar.bz2"],
                        "date"     => $PHP_7_1_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_1_VERSION.tar.gz",
                        "name"     => "PHP $PHP_7_1_VERSION (tar.gz)",
                        "sha256"   => $PHP_7_1_SHA256["tar.gz"],
                        "date"     => $PHP_7_1_DATE,
                    ),
                    array(
                        "filename" => "php-$PHP_7_1_VERSION.tar.xz",
                        "name"     => "PHP $PHP_7_1_VERSION (tar.xz)",
                        "sha256"   => $PHP_7_1_SHA256["tar.xz"],
                        "date"     => $PHP_7_1_DATE,
                    ),
                ),
            ),
        ),
    );
})();

// Get latest release version and info.
function release_get_latest() {
    global $RELEASES;

    $version = null;
    $current = null;
    foreach ($RELEASES as $versions) {
        foreach ($versions as $ver => $info) {
            if (version_compare($ver, $version) > 0) {
                $version = $ver;
                $current = $info;
            }
        }
    }

    return [ $version, $current ];
}
