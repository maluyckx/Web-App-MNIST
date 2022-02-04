import "../../styles/Home/BlockChoice.css"
import {Link} from "react-router-dom";

function BlockChoice({name, img_link, description, link_to}) {
    if (link_to === ""){
        return (
            <div className="containerBlock">
                <h3>{name}</h3>
                <img className='img-link' src={img_link} alt={`${img_link} cover`} />
                <p className="desc_text">{description}</p>
            </div>
        );
    } else {
        return (
            <Link to={link_to}>
                <div className="containerBlock">
                    <h3>{name}</h3>
                    <img className='img-link' src={img_link} alt={`${img_link} cover`} />
                    <p className="desc_text">{description}</p>
                </div>
            </Link>
        );
    }
}


export default BlockChoice