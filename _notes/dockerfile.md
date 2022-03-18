







    COPY — copies local files recursively, given explicit source and destination files or directories. With COPY, you must declare the locations.
    ADD — copies local files recursively, implicitly creates the destination directory when it doesn’t exist, and accepts archives as local or remote URLs as its source, which it expands or downloads respectively into the destination directory.

While subtle, the differences between ADD and COPY are important. Be aware of these differences to avoid potential security issues:

    When remote URLs are used to download data directly into a source location, they could result in man-in-the-middle attacks that modify the content of the file being downloaded. Moreover, the origin and authenticity of remote URLs need to be further validated. When using COPY the source for the files to be downloaded from remote URLs should be declared over a secure TLS connection and their origins need to be validated as well.
    Space and image layer considerations: using COPY allows separating the addition of an archive from remote locations and unpacking it as different layers, which optimizes the image cache. If remote files are needed, combining all of them into one RUN command that downloads, extracts, and cleans-up afterwards optimizes a single layer operation over several layers that would be required if ADD were used.
    When local archives are used, ADD automatically extracts them to the destination directory. While this may be acceptable, it adds the risk of zip bombs and Zip Slip vulnerabilities that could then be triggered automatically.




